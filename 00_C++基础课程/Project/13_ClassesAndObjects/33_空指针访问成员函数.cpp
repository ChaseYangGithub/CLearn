#include<iostream>
using namespace std;

//��ָ����ʳ�Ա����
//C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
//����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��

//��Ȥ��
class Interest {
public:
	void showClassName() {
		cout << "����Interest��" << endl;
	}
	void showInterest() {
		if (this == NULL) {
			return;
		}
		//û���������ᱨ��
		cout << a << endl;
	}
public:
	int a;
};

//��ָ����ʳ�Ա����������
void testNullPointer() {
	Interest *p=NULL;
	p->showClassName();//��ָ�룬���Ե��ó�Ա����
	p->showInterest();//���������Ա�������õ���thisָ�룬�Ͳ�������

}