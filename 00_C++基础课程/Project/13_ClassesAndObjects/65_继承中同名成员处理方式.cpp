#include<iostream>
using namespace std;
/*|
1. ����������ֱ�ӷ��ʵ�������ͬ����Ա
2. ����������������Է��ʵ�����ͬ����Ա
3. �������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա����������������Է��ʵ�������ͬ������
*/

class Test {
public:
	Test() {
		a = 100;
	}
	void func() {
		cout << "Test-Func" << endl;
	}
	void func(int a) {
		cout << "Test-fun(a)" << endl;
	}
public:
	int a;
};

class User :public Test{
public:
	User() {
		a = 200;
	}
	//�������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա����
	//�������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������
	void func() {
		cout << "User-func" << endl;
	}
public:
	int a;
};

void inheritTest3() {
	User u;
	cout << "User-func:" << u.a << endl;
	cout << "Test-func:" << u.Test::a << endl;
	u.func();
	u.Test::func();
	u.Test::func(100);
}