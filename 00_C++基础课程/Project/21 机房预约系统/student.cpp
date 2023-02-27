#include<iostream>
#include<fstream>
#include<vector>
#include "student.h"
#include "order.h"
#include "globalFile.h"
//Ĭ�Ϲ��캯��
Student::Student() {
	id = -1;//��ֹδ��ʼ������

}
//���ι��캯��
Student::Student(int id, std::string name, std::string password) {
	this->id = id;
	this->username = name;
	this->password = password;
	//��ʼ����������
	this->initComputer();
}
//�˵�����
void Student::operMenu() {
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "\t\t|\t1 ���ԤԼ\t|" << std::endl;
	std::cout << "\t\t|\t2 �鿴����ԤԼ\t|" << std::endl;
	std::cout << "\t\t|\t3 �鿴����ԤԼ\t|" << std::endl;
	std::cout << "\t\t|\t4 ȡ��ԤԼ\t|" << std::endl;
	std::cout << "\t\t|\t0 ע����¼\t|" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "�����빦��ѡ�";
}
//����ԤԼ
void Student::applyOrder() {
	int data = 0;//����
	int intNum = 0;//������
	int roomNum = 0;//����
	//��������
	while (true) {
		std::cout << "��������ʱ��Ϊ��һ������" << std::endl
			<< "1 ��һ" << std::endl
			<< "2 �ܶ�" << std::endl
			<< "3 ����" << std::endl
			<< "4 ����" << std::endl
			<< "5 ����" << std::endl
			<< "������ԤԼ������:";

		std::cin >> data;
		if (data >= 1 && data <= 5) {
			break;
		}
		system("cls");
		std::cout << "�����������������룡" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	//����ʱ��
	while (true) {
		std::cout << "ÿ��ʱ������£�" << std::endl
			<< "1 ����" << std::endl
			<< "2 ����" << std::endl
			<< "������ԤԼ��ʱ���:";
		std::cin >> intNum;
		if (intNum == 1 || intNum == 2) {
			break;
		}
		system("cls");
		std::cout << "�����������������룡" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	//�������
	while (true) {
		std::cout << "��ѡ������Ļ���!" << std::endl;
		//������Ϣ
		for (int i = 0; i < sC.size(); i++) {
			std::cout << i + 1 << " "
				<< sC[i].room << "�Ż��� ������"
				<< sC[i].capacity << " ��ǰ���ࣺ"
				<< sC[i].size << std::endl;
		}
		std::cin >> roomNum;
		if (roomNum >= 1 && roomNum <= sC.size() + 1 && !roomFull(roomNum)) {//��ʱĬ�Ϸ���ŵ���
			break;
		}
		system("cls");
		std::cout << "����������߻����� ���������룡" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	//�ļ�����
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::out | std::ios::app);
	//¼����Ϣ
	ofs << "���ڣ�" << data << " "
		<< "���룺" << intNum << " "
		<< "ѧ�ţ�" << this->id << " "
		<< "������" << this->username << " "
		<< "������" << roomNum << " "
		<< "״̬��" << 1 << std::endl;//����1 ���� 2ͬ�� 0ȡ�� -1ʧ��
	ofs.close();
	//����ԤԼ
	Order o;
	o.UpdateOrder();
	system("pause");
	system("cls");
}
//�鿴����ԤԼ
void Student::showMyApply() {
	Order o;
	//std::cout << o.size;//û����
	system("cls");
	//��������Ϊ��
	if (o.size == 0) {
		std::cout << "ԤԼ����Ϊ�գ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	//�������ݲ�Ϊ��
	for (int i = 0; i < o.size; i++) {
		//std::cout << atoi(o.data[i]["ѧ�ţ�"].c_str());
		//����id�Ƚ�   c_str()��stringת�����ַ�����  C�� atoi()��ָ��ָ���ַ���ת��Ϊ����
		if (atoi(o.data[i]["ѧ�ţ�"].c_str()) == this->id) {
			std::cout << i + 1;
			std::string mes = "��ԤԼ���ڣ���";
			//ԤԼʱ��
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
	}
	system("pause");
	system("cls");
}
//�鿴����ԤԼ
void Student::showAllApply() {
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
//ȡ��ԤԼ
void Student::cancleApply() {
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
		//����id�Ƚ�   c_str()��stringת�����ַ�����  C�� atoi()��ָ��ָ���ַ���ת��Ϊ����
		if (atoi(o.data[i]["ѧ�ţ�"].c_str()) == this->id) {
			if (o.data[i]["״̬��"] == "1" || o.data[i]["״̬��"] == "2") {//����ȡ��ԤԼ������
				v.push_back(i);
				std::cout << ++index;
				std::string mes = "��ԤԼ���ڣ���";
				//ԤԼʱ��
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
				}
				std::cout << mes << std::endl;
			}
		}
	}
	//ѡ��
	int choice = 0;
	while (true) {
		std::cout << "��������Ҫȡ��ԤԼ�����,0���أ�";
		std::cin >> choice;
		if (choice >= 0 && choice <= index) {
			if (choice == 0) {
				break;
			}
			else {
				//�޸�����
				o.data[v[choice-1]]["״̬��"] = "0";
				o.UpdateOrder();
				std::cout << "�Ѿ�ȡ��ԤԼ" << std::endl;
				break;
			}

		}
		system("cls");
		std::cout << "���벻�Ϸ���" << std::endl;
	}

	system("pause");
	system("cls");
}
//��ʼ��������Ϣ
void Student::initComputer() {
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	Computer c;
	while (ifs >> c.room && ifs >> c.capacity && ifs >> c.size) {
		sC.push_back(c);
	}
	ifs.close();
}

//������
bool Student::roomFull(int room) {
	for (std::vector<Computer>::iterator it = sC.begin(); it != sC.end(); it++) {
		if (it->room == room && it->capacity > it->size) {
			return false;
		}
	}
	return true;
}
//�޸Ļ�����Ϣ
//void Student::roomChange(int room) {
//	std::fstream fs;
//	fs.open(COMPUTER_FILE, std::ios::out | std::ios::app);
//	for (std::vector<Computer>::iterator it = sC.begin(); it != sC.end(); it++) {
//		if (it->room == room && it->capacity > it->size) {
//			return false;
//		}
//	}
//}