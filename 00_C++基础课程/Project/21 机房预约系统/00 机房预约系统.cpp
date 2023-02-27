#include<iostream>
#include "00 ����ԤԼϵͳ.h"
#include "globalFile.h"//�ļ�
#include "human.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include<fstream>



int main() {
	int select = -1;//Ĭ������ѡ�����
	while (true) {
		main_Menu();//������½�˵�ѡ��
		std::cin >> select;
		switch (select) {
		case 1://ѧ����½
			loginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ��¼
			loginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա��½
			loginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�����
			system("cls");
			std::cout << "��ӭ�´�ʹ�ã�" << std::endl;
			system("pause");
			return 0;
			break;
		default://Ĭ��ѭ��
			std::cout << "����������ѡ�" << std::endl;
			system("pause");
			system("cls");
			break;
		}

	}
	return 0;
}
//��ְ���Ӳ˵�
void teacherMenu(Human*& teacher) {
	int select = -1;
	Teacher* man;
	while (true) {
		//��ʦ�˵�
		teacher->operMenu();
		man = (Teacher*)teacher;
		std::cin >> select;
		switch (select) {
		case 1://�鿴����ԤԼ
			man->showAllApply();
			break;
		case 2://���ԤԼ
			man->reviewApply();
			break;
		case 0:
			delete man;
			std::cout << "ע���ɹ�" << std::endl;
			system("pause");
			system("cls");
			return;//�˳���cpp���ʹ��break�˳�ѭ������,��Ϊɾ����man
		default:
			std::cout << "����������ѡ�" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//ѧ���Ӳ˵�
void studentMenu(Human*& student) {
	int select = -1;//Ĭ��ѭ��
	Student* man;
	while (true) {
		//ѧ���˵�
		student->operMenu();
		man = (Student*)student;//ǿת��ֹ���ø���ĺ���
		std::cin >> select;
		switch (select) {
		case 1://����ԤԼ
			man->applyOrder();
			break;
		case 2://�鿴����ԤԼ
			man->showMyApply();
			break;
		case 3://�鿴����ԤԼ
			man->showAllApply();
			break;
		case 4://ȡ��ԤԼ
			man->cancleApply();
			break;
		case 0://ע����¼
			delete man;
			std::cout << "ע���ɹ�" << std::endl;
			system("pause");
			system("cls");
			return;//�˳���cpp���ʹ��break�˳�ѭ������
		default://Ĭ��ѭ��
			std::cout << "����������ѡ�" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//����Ա�Ӳ˵�
void managerMenu(Human*& manager) {
	int select = -1;//Ĭ��ѭ��
	Manager* man;
	while (true) {
		//����Ա�˵�
		manager->operMenu();
		man = (Manager*)manager;//ǿת��ֹ���ø���ĺ���
		std::cin >> select;
		switch (select) {
		case 1://����˺�
			man->addAccount();
			break;
		case 2://�鿴�˺�
			man->showAccount();
			break;
		case 3://�鿴����
			man->showComputer();
			break;
		case 4://���ԤԼ
			man->clearRecord();
			break;
		case 0://ע����¼
			delete man;
			std::cout << "ע���ɹ�" << std::endl;
			system("pause");
			system("cls");
			return;//�˳���cpp���ʹ��break�˳�ѭ������
		default://Ĭ��ѭ��
			std::cout << "����������ѡ�" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//��½���� �����ļ����͵�½���ʹ��ļ�ִ�е�½����
void loginIn(std::string fileName, int type) {
	Human* p = NULL;
	std::ifstream ifs;//�ļ���
	ifs.open(fileName, std::ios::in);//����ʽ���ļ�
	//�ļ�������
	if (!ifs.is_open()) {
		std::cout << "�ļ�������" << std::endl;
		system("pause");
		system("cls");
		ifs.close();
		return;
	}

	int id = -1;//��ֹδ��ʼ������
	std::string username;
	std::string pwd;
	//ѧ����ʦ���е�ѧ�Ž�ʦ��
	if (type == 1) {//ѧ����½
		std::cout << "������ѧ�ţ�";
		std::cin >> id;
	}
	else if (type == 2) {
		std::cout << "������ְ����:";
		std::cin >> id;
	}
	//ͨ������
	std::cout << "�������û�����";
	std::cin >> username;
	std::cout << "����������:";
	std::cin >> pwd;

	//��½��֤
	if (type == 1) {
		//ѧ����½��֤
		int did;
		std::string duser;
		std::string dpwd;
		while (ifs >> did && ifs >> duser && ifs >> dpwd) {//һ�ζ�ȡ���������Ҳ�Ϊ��
			if (did == id && duser == username && dpwd == pwd) {
				//У��ɹ�
				std::cout << "ѧ��" << username << "��½ϵͳ" << std::endl;
				system("pause");
				system("cls");
				p = new Student(id, username, pwd);
				//����ѧ����½ҳ��
				studentMenu(p);
				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ��½��֤
		int did;
		std::string duser;
		std::string dpwd;
		while (ifs >> did && ifs >> duser && ifs >> dpwd) {//һ�ζ�ȡ���������Ҳ�Ϊ��
			if (did == id && duser == username && dpwd == pwd) {
				//У��ɹ�
				std::cout << "��ʦ" << username << "��½ϵͳ" << std::endl;
				system("pause");
				system("cls");
				p = new Teacher(id, username, pwd);
				//�����ʦ��½ҳ��
				teacherMenu(p);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա��½��֤
		std::string duser;
		std::string dpwd;
		while (ifs >> duser && ifs >> dpwd) {//һ�ζ�ȡ���������Ҳ�Ϊ��
			if (duser == username && dpwd == pwd) {
				//У��ɹ�
				std::cout << "����Ա" << username << "��½ϵͳ" << std::endl;
				system("pause");
				system("cls");
				p = new Manager(username, pwd);
				//�������Ա�Ӳ˵�
				managerMenu(p);
				return;
			}
		}
	}
	std::cout << "��½��֤ʧ�ܣ������˻��������룡" << std::endl;
	system("pause");
	system("cls");
	return;

}

//������˵�
void main_Menu() {
	std::cout << "==================��ӭ��½����ԤԼϵͳ===========" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "\t\t|\t1 ѧ����½\t|" << std::endl;
	std::cout << "\t\t|\t2 ��ʦ��½\t|" << std::endl;
	std::cout << "\t\t|\t3 ����Ա��½\t|" << std::endl;
	std::cout << "\t\t|\t0 �˳�ϵͳ\t|" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "�������½ѡ�";
}