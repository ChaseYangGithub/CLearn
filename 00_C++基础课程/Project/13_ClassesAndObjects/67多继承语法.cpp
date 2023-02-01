#include<iostream>
using namespace std;

//总结： 多继承中如果父类中出现了同名情况，子类使用时候要加作用域

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

//语法：class 子类：继承方式 父类1 ，继承方式 父类2
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
//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void multyInherit() {
	Year y;
	cout << "sizeof year:" << sizeof(y) << endl;
	cout << y.Xray1::a << endl;
	cout << y.Xray2::a << endl;
}