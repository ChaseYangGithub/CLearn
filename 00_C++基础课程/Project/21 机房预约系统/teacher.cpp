#include<iostream>
#include<vector>
#include "teacher.h"
#include "order.h"
//Ĭ�Ϲ��캯��
Teacher::Teacher() {
	id = -1;
}
//�вι��캯��
Teacher::Teacher(int id, std::string name, std::string password) {
	this->id = id;
	this->username = name;
	this->password = password;
}
//��ʦ�����˵�
void Teacher::operMenu() {
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "\t\t|\t1 �鿴����ԤԼ\t|" << std::endl;
	std::cout << "\t\t|\t2 ���ԤԼ\t|" << std::endl;
	std::cout << "\t\t|\t0 ע����¼\t|" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "�����빦��ѡ�";
}
//��ʾ����ԤԼ
void Teacher::showAllApply() {
	Order o;
	//std::cout << o.size;//û����
	//��������Ϊ��
	system("cls");
	if (o.size == 0) {
		std::cout << "ԤԼ����Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	//�������ݲ�Ϊ��
	for (int i = 0; i < o.size; i++) {
		//std::cout << atoi(o.data[i]["ѧ�ţ�"].c_str());
		std::cout << i + 1;
		std::string mes = "��ԤԼ���ڣ���";
		//ԤԼʱ��
		//����id�Ƚ�   c_str()��stringת�����ַ�����  C�� atoi()��ָ��ָ���ַ���ת��Ϊ����
		switch (atoi(o.data[i]["���ڣ�"].c_str())) {
		case 1:
			mes += "һ ";
			break;
		case 2:
			mes += "�� ";
			break;
		case 3:
			mes += "�� ";
			break;
		case 4:
			mes += "�� ";
			break;
		case 5:
			mes += "�� ";
			break;
		}
		//ʱ���
		mes += (o.data[i]["ʱ�䣺"] == "1" ? "���� " : "���� ");
		//ѧ��
		mes += "ѧ�ţ�" + o.data[i]["ѧ�ţ�"];
		//����
		mes += " ������" + o.data[i]["������"];
		//����
		mes += " ������" + o.data[i]["������"];
		//״̬
		mes += " ״̬��";
		switch (atoi(o.data[i]["״̬��"].c_str())) {
		case 1:
			mes += "�����";
			break;
		case 2:
			mes += "ԤԼ�ɹ�";
			break;
		case 0:
			mes += "ȡ��ԤԼ";
			break;
		case -1:
			mes += "ԤԼʧ��";
			break;
		}
		std::cout << mes << std::endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ
void Teacher::reviewApply() {
	Order o;
	system("cls");
	//��������Ϊ��
	if (o.size == 0) {
		std::cout << "ԤԼ����Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 0;
	std::vector<int> v;//��¼ָ�����ݵ����
	//�������ݲ�Ϊ��
	for (int i = 0; i < o.size; i++) {
		if (o.data[i]["״̬��"] == "1") {//�������ԤԼ������
			v.push_back(i);
			std::cout << ++index;
			std::string mes = "��ԤԼ���ڣ���";
			//ԤԼʱ��
			//����id�Ƚ�   c_str()��stringת�����ַ�����  C�� atoi()��ָ��ָ���ַ���ת��Ϊ����
			switch (atoi(o.data[i]["���ڣ�"].c_str())) {
			case 1:
				mes += "һ ";
				break;
			case 2:
				mes += "�� ";
				break;
			case 3:
				mes += "�� ";
				break;
			case 4:
				mes += "�� ";
				break;
			case 5:
				mes += "�� ";
				break;
			}
			//ʱ���
			mes += (o.data[i]["ʱ�䣺"] == "1" ? "���� " : "���� ");
			//ѧ��
			mes += "ѧ�ţ�" + o.data[i]["ѧ�ţ�"];
			//����
			mes += " ������" + o.data[i]["������"];
			//����
			mes += " ������" + o.data[i]["������"];
			//״̬
			mes += " ״̬�������";
			std::cout << mes << std::endl;
		}
	}
	//ѡ��
	int choice = 0;
	int ans = 1;
	bool state = true;
	while (state) {
		std::cout << "��������Ҫȡ��ԤԼ�����,0���أ�";
		std::cin >> choice;
		if (choice >= 0 && choice <= index) {//�Ϸ�ѡ��
			if (choice == 0) {//�˳����
				break;
			}
			else {
				//�޸�����
				while (true) {//��˵�ǰ����
					std::cout << "2 ͨ��\n 1 ��ͨ��\n0 ����\n�����룺";
					std::cin >> ans;
					if (ans == 0 || ans ==1 || ans == 2) {
						if (ans == 0) {//ȡ����˵�ǰ����
							break;
						}
						else if (ans == 2) {
							o.data[v[choice - 1]]["״̬��"] = "2";//vector��Ŵ�0 ѡ���1
						}else{
							o.data[v[choice - 1]]["״̬��"] ="-1";
						}
						o.UpdateOrder();
						system("cls");
						std::cout << "�����������" << std::endl;
						state = false;
						break;
					}
				}

			}
		}
		if (state) {
			system("cls");
			std::cout << "���벻�Ϸ���" << std::endl;
		}
		system("pause");
		system("cls");
	}
}