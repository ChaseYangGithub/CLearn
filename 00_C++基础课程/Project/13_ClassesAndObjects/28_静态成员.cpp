#include<iostream>
using namespace std;
//��̬��Ա

//������
class Fox {
public:
	//��̬��Ա�����ص㣺
	//1 �ڱ���׶η����ڴ�
	//2 ���������������ʼ������
	//3 ���ж�����ͬһ��
	static int a;	//��̬����
	int c;

	//��̬��Ա�����ص㣺
	//1 ������һ������
	//2 ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	static void func() {
		cout << "func����" << endl;
		a = 100;
		//c = 200;//���󣬲����Է��ʷǾ�̬��Ա����
	}
private:
	static int b;//��̬��Ա����Ҳ�з���Ȩ��
	static void func2() {
		cout << "func2����" << endl;
	}
};

//�����ʼ��
int Fox::a = 100;
int Fox::b = 10;

void staticTest() {
	//��̬��Ա���������ַ��ʷ�ʽ

	//ͨ���������
	Fox f;
	f.a = 100;
	cout << "f.a=" << f.a << endl;
	Fox  f2;
	f2.a = 200;
	cout << "f.a=" << f.a << endl;	//����һ������
	cout << "f2.a=" << f2.a << endl;

	//ͨ������
	cout << "a=" << Fox::a << endl;
	//cout << "b=" << Person::b << endl;//˽��Ȩ�޷��ʲ���

	//��̬��Ա���������ַ�ʽ

	//ͨ������
	f.func();
	//ͨ������
	Fox::func();
	//Fox::func2();	//˽��Ȩ�޷��ʲ���
}