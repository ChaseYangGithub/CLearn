#include<iostream>
#include "workerManager.h"	//ְ����
#include"worker.h"			//ְ���������
#include"employee.h"		//Ա����
#include"manager.h"			//������
#include"boss.h"			//�ϰ���
void test();
int main() {
	WorkerManager wm;
	int choice = 0;//����ѡ��Ĭ��Ϊ0
	//test();//���Զ�̬
	while (true) {//�˵�ѭ����ʾ
		//չʾ�˵�
		wm.showMenu();
		std::cout << "����������ѡ��";
		std::cin >> choice;
		switch (choice) {//����ѡ��
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.addEmp();
			break;
		case 2://��ʾְ��
			wm.showEmp();
			break;
		case 3://ɾ��ְ��
			wm.delEmp();
			break;
		case 4://�޸�ְ��
			wm.modEmp();
			break;
		case 5://����ְ��
			wm.findEmp();
			break;
		case 6://����ְ��
			wm.sortEmp();
			break;
		case 7://����ļ�
			wm.clearFile();
			break;
		default:
			break;
		}
		system("cls");//����
	}
	return 0;
}

//���Զ�̬
void test() {
	Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;
	Worker* worker2 = NULL;
	worker2 = new Manager(2, "����", 1);
	worker2->showInfo();
	delete worker2;
	Worker* worker3 = NULL;
	worker3 = new Boss(3, "����", 1);
	worker3->showInfo();
	delete worker3;
}