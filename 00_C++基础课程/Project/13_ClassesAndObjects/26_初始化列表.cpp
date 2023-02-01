#include<iostream>
using namespace std;
//初始化列表语法

//对象dog
class Dog {
public:
	//初始化列表方式初始化
	Dog(int a, int b, int c) :a(a), b(b), c(c) {

	}
public:
	int a;
	int b;
	int c;
};

//初始化列表
void initialList() {
	Dog c(10,20,30);
	cout << "a=" << c.a << endl;
	cout << "b=" << c.b << endl;
	cout << "c=" << c.c << endl;
}