#include<iostream>
using namespace std;

//菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
//利用虚继承可以解决菱形继承问题
class Animal {
public:
	int age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类

class Sheep :virtual public Animal {};
class Tuo :virtual public Animal {};
class SheepTuo :public Sheep, public Tuo {};

void virtualInherit() {
	SheepTuo t;
	t.Sheep::age = 100;
	t.Tuo::age = 200;
	cout << "t.Sheep::age = " << t.Sheep::age << endl;
	cout << "t.Tuo::age = " << t.Tuo::age << endl;
	cout << "t.age = " << t.age << endl;
}