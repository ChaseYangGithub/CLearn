#include "workerManager.h"	//ְ����
#include"worker.h"			//ְ���������
#include"employee.h"		//Ա����
#include"manager.h"			//������
#include"boss.h"			//�ϰ���
#include<iostream>//IO
#include<fstream>//�����ļ�����
//using namespace std;//������ʹ�ã����ʹ�÷�������include֮��
//using std::cout;

//ְ���๹�캯��
WorkerManager::WorkerManager() {
	std::ifstream ifs;//�ļ���ȡ������
	ifs.open(FILENAME, std::ios::in);

	//�ļ�������
	if (!ifs.is_open()) {
		//std::cout << "�ļ�������" << std::endl;//�������
		this->empNum = 0;//��ʼ������
		this->fileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
		this->empArray = NULL;//��ʼ������ָ��
		ifs.close();//�ر��ļ�
		return;
	}
	//�ļ�����-û�м�¼
	char ch;
	ifs >> ch;//��ȡһ���ַ�--���Ϊ�ն�ȡ��ʱ�ļ������ж�λ
	if (ifs.eof()) {//�����ļ�β
		//std::cout << "�ļ�Ϊ��" << std::endl;//�������
		this->empNum = 0;//��ʼ������
		this->fileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
		this->empArray = NULL;//��ʼ������ָ��
		ifs.close();//�ر��ļ�
		return;
	}
	//�ļ�����������
	int num = this->getNum();
	//std::cout << "ְ������Ϊ��" << num << std::endl;//����
	this->empNum = num;//���³�Ա����
	//����ְ������������
	this->empArray = new Worker * [this->empNum];
	//��ʼ��ְ��������
	initEmp();
	//���Գ�ʼ��
	/*for (int i = 0; i < empNum; i++) {
		std::cout << "ְ���ţ�" << this->empArray[i]->id
			<< "\tְ��������" << this->empArray[i]->name
			<< "\t���ű�ţ�" << this->empArray[i]->deptId << std::endl;
	}*/

}

//ְ������������
WorkerManager::~WorkerManager() {
	//�ͷŶѿռ�
	if (this->empArray != NULL) {//�ͷŶѿռ�ְ������
		delete[] this->empArray;
	}
}\

//����ļ�
void WorkerManager::clearFile() {
	//ȷ����ʾ
	int select = 0;
	do {
		std::cout << "��ȷ��Ҫ��գ�" << std::endl
			<< "1 ȷ��" << std::endl
			<< "2 ����" << std::endl
			<< "ѡ��";
		std::cin >> select;
	} while (select != 1 && select != 2);
	//����ļ�
	if (select == 1) {
		//�ļ����
		std::ofstream ofs(FILENAME, std::ios::trunc);//����ļ����ڣ���ɾ���ٽ���
		ofs.close();
		//��ն�������
		if (this->empArray != NULL) {
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < empNum; i++) {
				if (this->empArray[i] != NULL) {
					delete this->empArray[i];//�ͷ�ÿ����������
				}
			}
			//ɾ����������ָ��

			delete[] this->empArray;
			this->empArray = NULL;
			this->empNum = 0;
			this->fileIsEmpty = true;
		}
		std::cout << "����ɹ���" << std::endl;
	}
	system("pause");
	system("cls");
}

//����ְ����Ϣ
void WorkerManager::sortEmp() {
	//�ļ������ڻ�������Ϊ��
	if (this->fileIsEmpty) {
		std::cout << "�ļ������ڻ�����ϢΪ��" << std::endl;
	}
	else {
		std::cout<< "��ѡ������ʽ��" << std::endl
			<< "1 ��ְ������������" << std::endl
			<< "2 ���ù��Ž�������" << std::endl;
		int select = 0;
		do {
			std::cout << "ѡ������";
			std::cin >> select;
		} while (select != 1 && select != 2);
		//ѡ������
		for (int i = 0; i < empNum; i++) {
			int Max = i;
			for (int j = i + 1; j < empNum; j++) {
				//��������
				if (select == 1) {
					if (empArray[Max]->id > empArray[j]->id) {
						Max = j;
					}
				}
				else {//��������
					if (empArray[Max]->id < empArray[j]->id) {
						Max = j;
					}
				}
			}
			if (i != Max) {//���ݽ���--ÿ�δ�ѭ�������/Сֵ
				Worker* temp = empArray[i];
				empArray[i] = empArray[Max];
				empArray[Max] = temp;
			}
		}
		std::cout << "����ɹ��������Ľ��Ϊ��" << std::endl;
		this->save();//���浽�ļ�
		this->showEmp();
	}
}

//����ָ��ְ����Ϣ
void WorkerManager::findEmp() {
	//�ļ������ڻ�������Ϊ��
	if (this->fileIsEmpty) {
		std::cout << "�ļ������ڻ�������Ϊ��" << std::endl;
	}
	else {
		std::cout << "��ѡ����ҷ�ʽ��" << std::endl
			<< "1 ����ְ����Ų���" << std::endl
			<< "2 ����ְ����������" << std::endl;
		int select = 0;
		do {//����ѡ��
			std::cout << "���ҷ�ʽ��";
			std::cin >> select;
		} while (select != 1 && select != 2);
		if (select == 1) {// ����ְ����Ų���
			int id;
			std::cout << "������ְ����ţ�";
			std::cin >> id;
			int index = isExit(id);//�ж������Ƿ����
			if (index != -1) {
				std::cout << "���ҳɹ���ְ����Ϣ���£�" << std::endl;
				this->empArray[index]->showInfo();
			}
			else {
				std::cout << "����ʧ�ܣ����޴���" << std::endl;
			}
		}
		else if (select == 2) {//������������
			std::string name;
			std::cout << "��������ҵ�������";
			std::cin >> name;
			//�ȶ���Ϣ
			bool flag = false;//���ұ�־
			for (int i = 0; i < empNum; i++) {
				if (this->empArray[i]->name == name) {
					std::cout << "���ҳɹ�������Ϊ" << name 
						<< "����Ϣ���£�"<<std::endl;
					flag = true;
					this->empArray[i]->showInfo();
				}
			}
			if (flag == false) {//����ʧ��
				std::cout << "��ѯʧ�ܣ����޴���" << std::endl;
			}
		}
		else {
			std::cout << "����ѡ�����" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::modEmp() {
	if (this->fileIsEmpty) {//�ļ������ڻ���Ϊ��
		std::cout << "�ļ������ڻ��߼�¼Ϊ��" << std::endl;
	}
	else {
		std::cout << "�������޸�ְ���ı�ţ�";
		int id;
		std::cin >> id;

		int index = this->isExit(id);
		if (index != -1) {//ְ���Ŵ���
			//��ȡԭ������
			int id = this->empArray[index]->id;
			std::string name = this->empArray[index]->name;
			int dId = this->empArray[index]->deptId;
			//�޸�����
			//����
			std::cout << "ԭ��������" <<name<< "�޸�Ϊ������";
			std::cin >> name;
			//��λѡ��
			int state = 0;
			std::cout << "ԭ�и�λ��"<<dId<<"��ѡ���ְ���ĸ�λ��" << std::endl;
			std::cout << "1����ְͨ��" << std::endl;
			std::cout << "2������" << std::endl;
			std::cout << "3���ϰ�" << std::endl;
			do {
				state = 0;//Ĭ��ִ��һ��
				std::cout << "ѡ���ְ���ĸ�λ��";
				std::cin >> dId;
				if (dId != 1 && dId != 2 && dId != 3) {//���Ϸ��ظ�ִ��
					state = 1;
				}
			} while (state);
			//��Ϣ¼��
			Worker* worker = NULL;
			switch (dId) {//����ְλ���ò�ͬ����
			case 1://��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2://����
				worker = new Manager(id, name, 2);
				break;
			case 3://�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default://���ⲻ����
				break;
			}
			//ɾ��ԭ������
			delete this->empArray[index];
			//�������ݣ����ݱ���
			this->empArray[index] = worker;
			//�޸������ʾ
			std::cout << "�޸����" << std::endl;
			//���浽�ļ���
			this->save();
		}
		else {
			std::cout << "�޸�ʧ�ܣ����޴���" << std::endl;
		}
	}
	//�����ⰴ�� ����
	system("pause");
	system("cls");
}

//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
int WorkerManager::isExit(int id) {
	int index = -1;
	for (int i = 0; i < this->empNum; i++) {
		if (this->empArray[i]->id == id) {//ְ���Ŵ���
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��ְ��
void WorkerManager::delEmp() {
	//1 �ļ������ڻ���������
	if (this->fileIsEmpty) {
		std::cout << "�ļ������ڻ��߼�¼Ϊ��" << std::endl;
	}
	else {
		//����ְ�����ɾ��
		std::cout << "��������Ҫɾ����ְ���ţ�";
		int id = 0;
		std::cin >> id;
		int index = this->isExit(id);
		if (index != -1) {//���ݴ���
			for (int i = index; i < this->empNum; i++) {//�Ӵ�ɾ��������������ǰ��
				this->empArray[i] = this->empArray[i + 1];
			}
			this->empNum--;
			this->save();//ɾ��������ͬ�����ļ�
			std::cout << "ɾ���ɹ�" << std::endl;
		}
		else {//���ݲ�����
			std::cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

//��ʾְ��
void WorkerManager::showEmp() {
	//�ж����ݴ治����
	if (this->fileIsEmpty) {
		std::cout << "�ļ������ڻ���Ϊ��" << std::endl;
	}
	else {
		for (int i = 0; i < empNum; i++) {
			//���ö�̬���ýӿ�
			this->empArray[i]->showInfo();
		}
	}
	//��ͣ��Ļ
	system("pause");
	system("cls");
}

//��ʼ���ļ��е�Ա��
void WorkerManager::initEmp() {//���ļ��ж�ȡ�������ݲ��洢��������
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);//��ȡ�ļ�
	int id;
	std::string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		//���ݲ�ְͬλ������ͬ�Ķ���
		if (dId == 1) {//1 ��ͨԱ��
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {//2 ����
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) {//3 �ϰ�
			worker = new Boss(id, name, dId);
		}
		//�����������
		this->empArray[index] = worker;
		index++;
	}
}

//ͳ���ļ��е�����
int WorkerManager::getNum() {//ͨ����ȡ�ļ���ȡ�ļ���Ŀ
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);//��ȡ
	//�м����
	int id;
	std::string name;
	int dId;

	int num = 0;//ͳ������
	while (ifs >> id && ifs >> name && ifs >> dId) {//ÿ�δ��ļ��ж�ȡ�������ݣ�һ��Ϊһ���˵ģ�
		//��¼����
		num++;
	}
	ifs.close();//�ر��ļ�
	return num;//��������
}
//�����ļ�
void WorkerManager::save() {
	std::ofstream ofs;//����������
	ofs.open(FILENAME, std::ios::out);//Ϊд�ļ������ļ�
	for (int i = 0; i < this->empNum; i++) {//���ݴ洢
		ofs << this->empArray[i]->id << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->deptId << std::endl;
	}
	//�ر��ļ�
	ofs.close();
}

//����ְ��
void WorkerManager::addEmp() {
	std::cout << "����������ְ��������";
	int addNum = 0;
	std::cin >> addNum;
	if (addNum > 0) {//�������ݺϷ�
		//�����¿ռ��С
		int newSize = this->empNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];//ע��ʹ����Ҫ����
		//��ԭ�пռ�������ת�Ƶ��¿ռ���
		if (this->empArray != NULL) {//ԭ�����ݴ���
			for (int i = 0; i < this->empNum; i++) {
				if (i < newSize) {//���û���жϱ���C6386 ��Ȼ�ƺ�����û��ʲô����
					newSpace[i] = this->empArray[i];
				}
			}
		}
		//����������
		for (int i = 0; i < addNum; i++) {
			int id;
			std::string name;
			int dId;
			//��Ϣ����
			std::cout << "***********************************" << std::endl;
			//���
			std::cout << "�������" << i + 1 << "��ְ����ţ�";
			std::cin >> id;
			//����
			std::cout << "�������" << i + 1 << "��ְ��������";
			std::cin >> name;
			//��λѡ��
			int state = 0;
			std::cout << "��ѡ���ְ���ĸ�λ��" << std::endl;
			std::cout << "1����ְͨ��" << std::endl;
			std::cout << "2������" << std::endl;
			std::cout << "3���ϰ�" << std::endl;
			do {
				state = 0;//Ĭ��ִ��һ��
				std::cout << "ѡ���ְ���ĸ�λ��";
				std::cin >> dId;
				if (dId != 1 && dId != 2 && dId != 3) {//���Ϸ��ظ�ִ��
					state = 1;
				}
			} while (state);
			//��Ϣ¼��
			Worker* worker = NULL;
			switch (dId) {//����ְλ���ò�ͬ����
			case 1://��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2://����
				worker = new Manager(id, name, 2);
				break;
			case 3://�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default://���ⲻ����
				break;
			}
			//�����¿ռ�
			int t = this->empNum + i;
			if (t < newSize) {//���ж�ͬ�Ͼ�������
				newSpace[t] = worker;
			}
		}
		//�ͷ�ԭ�пռ�
		delete[] this->empArray;	//�ͷ�����ռ�
		//�����¿ռ�ָ��
		this->empArray = newSpace;
		//���¸���
		this->empNum = newSize;
		//����ְ����Ϊ�ձ�־
		this->fileIsEmpty = false;
		//�����ļ�
		this->save();
		//��ʾ��Ϣ
		std::cout << "\n�ɹ����" << addNum << " ����ְ����" << std::endl;
	}
	else {//�������ݲ��Ϸ�
		std::cout << "�������ݲ��Ϸ�" << std::endl;
	}
	system("pause");
	system("cls");
}

//��ʾ�˵�
void WorkerManager::showMenu() {
	std::cout << "********************************************" << std::endl;
	std::cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << std::endl;
	std::cout << "*************  0.�˳��������  *************" << std::endl;
	std::cout << "*************  1.����ְ����Ϣ  *************" << std::endl;
	std::cout << "*************  2.��ʾְ����Ϣ  *************" << std::endl;
	std::cout << "*************  3.ɾ����ְְ��  *************" << std::endl;
	std::cout << "*************  4.�޸�ְ����Ϣ  *************" << std::endl;
	std::cout << "*************  5.����ְ����Ϣ  *************" << std::endl;
	std::cout << "*************  6.���ձ������  *************" << std::endl;
	std::cout << "*************  7.��������ĵ�  *************" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;
}

//�˳�����
void WorkerManager::exitSystem() {
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);// ����I/O�����������˳�����
}