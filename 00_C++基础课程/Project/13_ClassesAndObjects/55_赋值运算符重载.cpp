#include<iostream>
using namespace std;

class Ops {
public:
	Ops(int age) {
		//���������ݷŵ�����
		mage = new int(age);
	}
	//���ظ�ֵ�����
	Ops& operator=(Ops& p) {
		if (mage !=NULL) {
			delete mage;
			mage = NULL;
		}
		//�������ṩ��ǳ��������
		//mage = p.mage;

		//�ṩ��������ǳ����������
		mage = new int(*p.mage);
		//��������
		return *this;
	}

	//��������
	~Ops() {
		if (mage != NULL) {
			delete mage;
			mage = NULL;
		}
	}
	int *mage;
};


void operatorTest5() {
	Ops p1(10);
	Ops p2(20);
	Ops p3(30);
	p3 = p2 = p1;
	cout << "p1:" <<*p1.mage << endl;
	cout << "p2:" <<*p2.mage << endl;
	cout << "p3:" <<*p3.mage << endl;
}