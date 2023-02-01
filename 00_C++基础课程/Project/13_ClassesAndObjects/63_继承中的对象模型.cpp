#include<iostream>
using namespace std;
//继承中的对象模型

class Base {
public:
	int a;
protected:
	int b;
private:
	int c;//私有成员只是被隐藏，但是还是会被继承下去
};

//公共继承
class Son :public Base {
public:
	int d;
};

void inheritTest() {
	cout << "sizeof Son=" << sizeof(Son) << endl;//此处大小为16
}