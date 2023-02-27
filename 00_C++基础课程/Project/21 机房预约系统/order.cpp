#include<iostream>
#include<fstream>
#include<map>
#include "order.h"
#include "globalFile.h"

//���캯��
Order::Order() {
	std::string data;//����
	std::string time;//������
	std::string id;//ѧ��
	std::string username;//����
	std::string room;//����
	std::string status;//״̬
	std::ifstream ifs;
	std::string key;//��ֵ ���ڴ洢���ݵ�����
	std::string value;//ֵ ���ڴ洢���ݵ�����
	std::map<std::string, std::string> m;
	int pos = -1;//���ڼ�¼��λ��
	this->size = 0;//��¼��
	ifs.open(ORDER_FILE, std::ios::in);
	while (ifs >> data && ifs >> time && ifs >> id && ifs >> username && ifs >> room && ifs >> status) {
		//���Դ���--���Զ�ȡ
	/*	std::cout << data << std::endl;
		std::cout << time << std::endl;
		std::cout << id << std::endl;
		std::cout <<username << std::endl;
		std::cout << room << std::endl;
		std::cout << status << std::endl;*/
		m.clear();
		//std::map<std::string, std::string> m;
		//map�Դ���.clear()���������map��洢���������ݣ������mapֵ�洢����ָ�룬�������ֵ���ᱻ���
		
		//���� ���ļ������ַ�ռ��������λ
		//pos = (int)data.find("��");//0
		//pos = (int)data.find("��");//2
		pos = (int)data.find("��");//4--find�ҵ��ǵ�ǰ�ַ���ʼλ�ã��������һ�����ݿ�ʼҪ+2����ǰ���ģ�
		//���ʹ��Ӣ��:��+1
		//std::cout << pos;
		if (pos != -1) {
			//����pos��ʼ  ����Ϊn��string
			key = data.substr(0, pos + 2);//��עֵ �� �±�0��ʼ����Ϊpos+2������
			value = data.substr(pos + 2, data.size() - pos - 1);
		/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//������
		pos = (int)time.find("��");//����ð����������
		if (pos != -1) {
			//����pos��ʼ  ����Ϊn��string
			key = time.substr(0, pos + 2);//��עֵ
			value = time.substr(pos + 2, time.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//ѧ��
		pos = (int)id.find("��");//����ð����������
		if (pos != -1) {
			//����pos��ʼ  ����Ϊn��string
			key = id.substr(0, pos + 2);//��עֵ
			value = id.substr(pos + 2, id.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//����
		pos = (int)username.find("��");//����ð����������
		if (pos != -1) {
			//����pos��ʼ  ����Ϊn��string
			key = username.substr(0, pos + 2);//��עֵ
			value = username.substr(pos + 2, username.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//����
		pos = (int)room.find("��");//����ð����������
		if (pos != -1) {
			//����pos��ʼ  ����Ϊn��string
			key = room.substr(0, pos + 2);//��עֵ
			value = room.substr(pos + 2, room.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//״̬
		pos = (int)status.find("��");//����ð����������
		if (pos != -1) {
			//����pos��ʼ  ����Ϊn��string
			key = status.substr(0, pos + 2);//��עֵ
			value = status.substr(pos + 2, status.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//�������ݵ�����
		this->data.insert(std::make_pair(this->size, m));
		this->size++;//ԤԼ������1
	}
	//����ԤԼ��¼����
	//std::string test = this->data[0]["���ڣ�"];//2
	//std::cout << test;
	
	//�������--�����ļ����
	//for (std::map<int, std::map<std::string, std::string>>::iterator it = this->data.begin(); it != this->data.end(); it++) {
	//	std::cout << "key:" << it->first << " value:\t";
	//	for (std::map<std::string, std::string>::iterator t = it->second.begin(); t != it->second.end(); t++) {//�����������
	//		std::cout << t->first << " " << t->second << " ";
	//	}
	//	std::cout << std::endl;
	//}
	ifs.close();
}
//����ԤԼ��¼
void Order::UpdateOrder() {
	if (this->size == 0) {
		return;//˵��û��Ҫ���µ�����
	}

	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);//���������ɾ���ڴ���
	for (int i = 0; i < this->size; i++) {
		ofs << "���ڣ�" << this->data[i]["���ڣ�"] << " "; // find element matching _Keyval or insert value-initialized value
		ofs << "���룺" << this->data[i]["���룺"] << " ";
		ofs << "ѧ�ţ�" << this->data[i]["ѧ�ţ�"] << " ";
		ofs << "������" << this->data[i]["������"] << " ";
		ofs << "������" << this->data[i]["������"] << " ";
		ofs << "״̬��" << this->data[i]["״̬��"] << std::endl;
	}
	ofs.close();
}