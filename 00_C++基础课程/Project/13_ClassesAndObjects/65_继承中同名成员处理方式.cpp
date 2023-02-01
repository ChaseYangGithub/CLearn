#include<iostream>
using namespace std;
/*|
1. 子类对象可以直接访问到子类中同名成员
2. 子类对象加作用域可以访问到父类同名成员
3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
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
	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
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