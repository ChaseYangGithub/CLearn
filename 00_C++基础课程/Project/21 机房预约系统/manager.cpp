#include<iostream>
#include<fstream>
#include<algorithm>//for_each
#include "manager.h"
#include "globalFile.h"

//Ĭ�Ϲ��캯��
Manager::Manager() {

}
//�вι��캯��
Manager::Manager(std::string username, std::string password) {
	this->username = username;
	this->password = password;
	//��ʼ������
	this->initVector();
	//��ʼ��������Ϣ
	this->initComputer();
}

//��ʾ����Ա�����˵�
void Manager::operMenu() {
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "\t\t|\t1 ����˺�\t|" << std::endl;
	std::cout << "\t\t|\t2 �鿴�˺�\t|" << std::endl;
	std::cout << "\t\t|\t3 �鿴����\t|" << std::endl;
	std::cout << "\t\t|\t4 ���ԤԼ\t|" << std::endl;
	std::cout << "\t\t|\t0 ע����¼\t|" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "�����빦��ѡ�";
}

//����˺�
void Manager::addAccount() {
	std::string fileName;//�ļ�����
	std::string name;
	std::string password;
	std::string pwd;//У��
	bool repeat = true;//�ظ�У��
	std::string errorType;//������Ϣ
	int id=-1;
	int select=-1;//ѡ��
	//����ѡ��
	while (true) {
		std::cout << "1 �����ʦ�˺�" << std::endl;
		std::cout << "2 ���ѧ���˺�" << std::endl;
		std::cout << "����������˺����ͣ�";
		std::cin >> select;
		if (select == 1) {
			fileName = TEACHER_FILE;
			errorType = "ְ������ظ�,���������룺";
			std::cout << "������ְ����ţ�";
			break;
		}
		else if (select == 2) {
			fileName = STUDENT_FILE;
			errorType = "ѧ��ѧ���ظ������������룺";
			std::cout << "������ѧ��ѧ�ţ�";
			break;
		}
	}
	//����ظ�
	while (repeat) {
		std::cin >> id;
		repeat = checkRepeat(id, select);
		if (repeat) {
			std::cout << errorType << std::endl;
		}
	}
	
	std::cout << "������������";
	std::cin >> username;
	//����
	while (true) {
		std::cout << "����������:";
		std::cin >> password;
		std::cout << "���ٴ���������:";
		std::cin >> pwd;
		if (password == pwd) {
			break;
		}
		else {
			system("cls");
			std::cout << "�����������벻һ�£����������룡" << std::endl;
		}
	}
	//¼���ļ�
	std::ofstream ofs;
	ofs.open(fileName, std::ios::out | std::ios::app);//д�ļ� ׷�ӷ�ʽ
	ofs << id << " " << username << " " << password << std::endl;
	std::cout << "��ӳɹ���" << std::endl;
	std::cout << "�����Ϣ��"<<id<<" "<<username<<" "<<password << std::endl;
	ofs.close();
	//���³�ʼ������
	initVector();
	system("pause");
	system("cls");

}

//ͨ�ô�ӡ
template<class T>
void printInfo(T& s) {
	std::cout << s.id <<"\t" << s.username<<"\t" << s.password << std::endl;
}
//��ʾ�˺�
void Manager::showAccount() {
	int select=-1;
	while (true) {
		std::cout << "1 �鿴���н�ʦ" << std::endl;
		std::cout << "2 �鿴����ѧ��" << std::endl;
		std::cout << "��ѡ��鿴����:";
		std::cin >> select;
		if (select != 1 && select != 2) {
			system("cls");
			std::cout << "������ѡ��鿴����"<<std::endl;
		}
		else {
			break;
		}
	}
	if (select == 1) {
		system("cls");
		std::cout << "ְ����\t����\t����" << std::endl;
		std::for_each(tV.begin(), tV.end(), printInfo<Teacher>);
	}
	else if (select == 2) {
		system("cls");
		std::cout << "ѧ��\t����\t����" << std::endl;
		std::for_each(sV.begin(), sV.end(), printInfo<Student>);
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer() {
	system("cls");
	std::cout << "������Ϣ���£�"<<std::endl;
	for (std::vector<Computer>::iterator it = cV.begin(); it != cV.end(); it++) {
		std::cout << "��ţ�" << it->room << "������" << it->capacity<<std::endl;
	}
	system("pause");
	system("cls");

}

//���ԤԼ��¼
void Manager::clearRecord() {
	//�����ļ�
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::trunc);//���������ɾ���ٴ���
	ofs.close();
	std::cout << "��ռ�¼�ɹ���" << std::endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector() {
	//��ȡ������ʦ
	std::ifstream ifs;
	//�п�
	ifs.open(TEACHER_FILE, std::ios::in);
	if (!ifs.is_open()) {
		std::cout << "��ʼ������--�ļ���ʦ��ȡʧ��" << std::endl;
		return;
	}
	//�����ÿ�
	tV.clear();
	Teacher t;
	//��ȡ����
	while (ifs >> t.id && ifs >> t.username && ifs >> t.password) {
		tV.push_back(t);
	}
	//����ͳ��
	//std::cout << "��ǰ��ʦ����Ϊ��" << tV.size() << std::endl;
	//�ر��ļ�
	ifs.close();

	//��ȡ����ѧ��
	ifs.open(STUDENT_FILE, std::ios::in);
	//�п�
	if (!ifs.is_open()) {
		std::cout << "��ʼ������--�ļ�ѧ����ȡʧ��" << std::endl;
		return;
	}
	//�����ÿ�
	sV.clear();
	//��ȡ����
	Student s;
	while (ifs >> s.id && ifs >> s.username && ifs >> s.password) {
		sV.push_back(s);
	}
	//����ͳ��
	//std::cout << "��ǰѧ������Ϊ��" << sV.size() << std::endl;
	//�ر��ļ�
	ifs.close();

}

//����ظ�����
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (std::vector<Teacher>::iterator it = tV.begin(); it != tV.end(); it++) {
			if (id == it->id) {
				return true;
			}
		}
	}
	else if(type==2) {
		for (std::vector<Student>::iterator it = sV.begin(); it != sV.end(); it++) {
			if (id == it->id) {
				return true;
			}
		}
	}
	return false;
}

//��ʼ��������Ϣ
void Manager::initComputer() {
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	Computer c;
	while (ifs >> c.room && ifs >> c.capacity&&ifs>>c.size) {
		cV.push_back(c);
	}
	//std::cout << "��ǰ����������" << cV.size() << std::endl;
	ifs.close();
}