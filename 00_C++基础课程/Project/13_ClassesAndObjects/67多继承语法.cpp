#include<iostream>
using namespace std;

//�ܽ᣺ ��̳�����������г�����ͬ�����������ʹ��ʱ��Ҫ��������

class Xray1 {
public:
	Xray1() {
		a = 100;
	}
public:
	int a;
};
class Xray2 {
public:
	Xray2() {
		a = 200;
	}
public:
	int a;
};

//�﷨��class ���ࣺ�̳з�ʽ ����1 ���̳з�ʽ ����2
class Year :public Xray1, public Xray2 {
public:
	Year() {
		c = 300;
		d = 400;
	}
public:
	int c;
	int d;

};
//��̳����ײ�����Աͬ�������
//ͨ��ʹ������������������ֵ�����һ������ĳ�Ա
void multyInherit() {
	Year y;
	cout << "sizeof year:" << sizeof(y) << endl;
	cout << y.Xray1::a << endl;
	cout << y.Xray2::a << endl;
}