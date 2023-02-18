#include<iostream>
#include<vector>//���Ա������
#include<map>//��Ų�������
#include<ctime>//�����
/*
* ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
* Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
* �����10��Ա�����䲿�ź͹���
* ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
* �ֲ�����ʾԱ����Ϣ
*/

#define CEHUA 0;
#define MEISHU 1;
#define YANFA 2;
//Ա��
class Worker {
public:
	std::string name;//����
	int salary{};//����----{}��ʼ��ȥ������
};
//����Ա��
void createWorker(std::vector<Worker>& v) {
	std::string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		Worker worker;
		worker.name = "Ա��";
		worker.name += nameseed[i];
		worker.salary = rand() % 10000 + 10000;//10000-20000
		//Ա����������
		v.push_back(worker);
	}
}
//Ա������
void selectGroup(std::vector<Worker>& v, std::multimap<int, Worker>& m) {
	for (std::vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		//����������ű��
		int depId = rand() % 3;//0,1,2
		//��Ա�����������
		//keyΪ���ű�ţ�valueΪ����ֹ�
		m.insert(std::make_pair(depId, *it));
	}
}

//���շ�����ʾ
void showWorkerByGroup(std::multimap<int, Worker>& m) {
	//�߻�����
	std::cout << "�߻����ţ�" << std::endl;
	std::multimap<int, Worker>::iterator pos = m.find(0);
	int count = m.count(0);//ͳ�ƾ�������
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++){
		std::cout << "������" << pos->second.name << " ���ʣ�" << pos->second.salary << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	//��������
	std::cout << "�������ţ�" << std::endl;
	pos = m.find(1);
	count = m.count(1);//ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		std::cout << "������" << pos->second.name << " ���ʣ�" << pos->second.salary << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	//�з�����
	std::cout << "�з����ţ�" << std::endl;
	pos = m.find(2);
	count = m.count(2);//ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		std::cout << "������" << pos->second.name << " ���ʣ�" << pos->second.salary << std::endl;
	}
}

void test91() {
	//����Ա��
	std::vector<Worker> worker;
	createWorker(worker);
	//Ա������
	std::multimap<int, Worker> sw;
	selectGroup(worker, sw);
	//������ʾԱ��
	showWorkerByGroup(sw);
}

