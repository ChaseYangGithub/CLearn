#include<iostream>
using namespace std;
//��ʼ���б��﷨

//����dog
class Dog {
public:
	//��ʼ���б�ʽ��ʼ��
	Dog(int a, int b, int c) :a(a), b(b), c(c) {

	}
public:
	int a;
	int b;
	int c;
};

//��ʼ���б�
void initialList() {
	Dog c(10,20,30);
	cout << "a=" << c.a << endl;
	cout << "b=" << c.b << endl;
	cout << "c=" << c.c << endl;
}