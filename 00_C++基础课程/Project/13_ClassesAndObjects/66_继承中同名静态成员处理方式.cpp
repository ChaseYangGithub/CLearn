#include<iostream>
using namespace std;
//继承中同名静态成员处理方式
/*
静态成员和非静态成员出现同名，处理方式一致
- 访问子类同名成员   直接访问即可
- 访问父类同名成员   需要加作用域
同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象 和 通过类名）
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
	cout<<"通过对象访问："<<endl;
	Wave a;
	cout << "Wave a:" << a.a << endl;
	cout << "Version a:" << a.Version::a << endl;
	a.func();
	a.Version::func();

	cout << "通过类名访问：" << endl;
	cout << "Wave a:" << Wave::a << endl;
	cout << "Version a:" << Wave::Version::a << endl;
	Wave::func();
	Wave::Version::func();
	Wave::Version::func(100);
}