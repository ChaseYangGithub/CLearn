#include<iostream>
using namespace std;

class Length {
	friend ostream& operator<<(ostream& out, Length& l);//重载左移运算符配合友元可以实现输出自定义数据类型
public:
	Length(int a, int b) {
		this->a = a;
		this->b = b;
	}

private:
	int a;
	int b;
};
//全局函数实现左移
//ostream对象只有一个
ostream& operator<<(ostream& out, Length& l) {
	out << "a:" << l.a << " b:" << l.b;
	return out;//带有返回值才可以使用链式编程无线追加
}

void operatorTest2() {
	Length l(10,10);
	cout << l << endl<<"hello world" << endl;//链式编程
}