#include<iostream>
using namespace std;
//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//总结1：对于内置的数据类型的表达式的的运算符是不可能改变的
//总结2：不要滥用运算符重载

//加号运算符重载
//作用：实现两个自定义数据类型相加的运算
class Key {
public:
	Key() {};
	Key(int a, int b) {
		this->a = a;
		this->b = b;
	}
	//成员函数实现+号运算符重载
	Key operator+(const Key& k) {
		Key temp;
		temp.a = this->a + k.a;
		temp.b = this->b + k.b;
		return temp;
	}
public:
	int a;
	int b;
};
//全局函数实现+号函数重载
Key operator+(const Key& p, const Key& q) {
	Key temp;
	temp.a = p.a + q.a;
	temp.b = p.b + q.b;
	return temp;
}

//运算符重载可以发生函数重载
Key operator+(const Key& p, int val) {
	Key temp;
	temp.a = p.a + val;
	temp.b = p.b + val;
	return temp;
}

void operatorTest(){
	Key p(1, 10);
	Key q(10, 100);
	//成员函数方式
	Key t = p + q;//等价于p.operator(q)
	cout << "a:" << t.a << " b:" << t.b << endl;

	Key t2 = p + 10;//等价于operator(p,10)
	cout << "a:" << t2.a << " b:" << t2.b <<endl;

	Key t3 = p + q;//等价于operator(p,q)
	cout << "a:" << t3.a << " b:" << t3.b << endl;


}