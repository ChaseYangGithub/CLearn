#include<iostream>
using namespace std;
//静态成员

//狐狸类
class Fox {
public:
	//静态成员变量特点：
	//1 在编译阶段分配内存
	//2 类内声明，类外初始化数据
	//3 所有对象共享同一份
	static int a;	//静态变量
	int c;

	//静态成员函数特点：
	//1 程序共享一个函数
	//2 静态成员函数只能访问静态成员变量
	static void func() {
		cout << "func调用" << endl;
		a = 100;
		//c = 200;//错误，不可以访问非静态成员变量
	}
private:
	static int b;//静态成员变量也有访问权限
	static void func2() {
		cout << "func2调用" << endl;
	}
};

//类外初始化
int Fox::a = 100;
int Fox::b = 10;

void staticTest() {
	//静态成员变量的两种访问方式

	//通过对象访问
	Fox f;
	f.a = 100;
	cout << "f.a=" << f.a << endl;
	Fox  f2;
	f2.a = 200;
	cout << "f.a=" << f.a << endl;	//共享一份数据
	cout << "f2.a=" << f2.a << endl;

	//通过类名
	cout << "a=" << Fox::a << endl;
	//cout << "b=" << Person::b << endl;//私有权限访问不到

	//静态成员函数的两种方式

	//通过对象
	f.func();
	//通过类名
	Fox::func();
	//Fox::func2();	//私有权限访问不到
}