#include<iostream>
using namespace std;
//�̳���ͬ����̬��Ա����ʽ
/*
��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��
- ��������ͬ����Ա   ֱ�ӷ��ʼ���
- ���ʸ���ͬ����Ա   ��Ҫ��������
ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʵķ�ʽ��ͨ������ �� ͨ��������
*/

class Version {
public:
	static void func() {
		cout << "Version-static void func" << endl;
	}
	static void func(int a) {
		cout << "Version-static void func(a)" << endl;
	}
public:
	static int a;
};
int Version::a = 100;

class Wave :public Version {
public:
	static void func() {
		cout << "Wave-static void func" << endl;
	}
	static void func(int a) {
		cout << "Wave-static void func(a)" << endl;
	}
public:
	static int a;
};
int Wave::a = 200;

void sameStaticFunc() {
	cout<<"ͨ��������ʣ�"<<endl;
	Wave a;
	cout << "Wave a:" << a.a << endl;
	cout << "Version a:" << a.Version::a << endl;
	a.func();
	a.Version::func();

	cout << "ͨ���������ʣ�" << endl;
	cout << "Wave a:" << Wave::a << endl;
	cout << "Version a:" << Wave::Version::a << endl;
	Wave::func();
	Wave::Version::func();
	Wave::Version::func(100);
}