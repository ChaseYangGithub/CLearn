#include<iostream>
using namespace std;
/*
��������
	��Ա�������const�����ǳ�Ϊ�������Ϊ ������ ���ƣ� void testJack() const{}
	�������ڲ������޸ĳ�Ա����
	��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�
������
	��������ǰ��const�Ƹö���Ϊ������
	������ֻ�ܵ��ó�����
*/

//�п���
class Jack {
public:
	Jack() {
		a = 1;
		b = 0;
	}
	//thisָ��ı�����һ��ָ�볣����ָ���ָ�򲻿��޸�
	//�������ָ��ָ���ֵҲ�������޸ģ���Ҫ����������
	void  showJack() const {
		// const Type* const pointer;
		//this = NULL; //�����޸�ָ���ָ�� Person* const this;
		//this->a = 100; //����thisָ��ָ��Ķ���������ǿ����޸ĵ�

		//const���γ�Ա��������ʾָ��ָ����ڴ�ռ�����ݲ����޸ģ�����mutable���εı���
		this->b = 100;
	}
	void funcJack() {
		a = 1000;
	}
public:
	int a;
	mutable int b;//���޸ģ��ɱ��
};


//const���ζ���  ������
void testConst() {

	const Jack p; //��������  
	cout << p.a << endl;
	//p.a = 100; //���������޸ĳ�Ա������ֵ,���ǿ��Է���
	p.b = 100; //���ǳ���������޸�mutable���γ�Ա����

	//��������ʳ�Ա����
	//p.funcJack(); //�������ܵ���const�ĺ���

}
