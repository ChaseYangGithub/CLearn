#include<iostream>
using namespace std;
//类对象作为类成员

//大象对象
class Elephant {
public:
	Elephant(string name) {
		ename = name;
		cout << "Elephant对象构造函数" << endl;
	}
	~Elephant() {
		cout << "Elephant对象析构函数" << endl;
	}
public:
	string ename;//大象名称
};
//动物对象
class Animal {
public:
	//初始化列表可以告诉编译器调用哪一个构造函数
	Animal(string namea,string namee):aname(namea),e(namee){
		cout << "动物的构造函数" << endl;
	}
	~Animal() {
		cout << "动物的析构函数" << endl;
	}
	void showAnimal() {
		cout << aname << "使用姓名：" << e.ename<< endl;
	}
public:
	string aname;
	Elephant e;
};


//类对象作为类成员测试
void testClass() {
	//当类中成员是其他类对象时，我们称该成员为 对象成员
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反
	Animal a("大象", "潘多拉");
	a.showAnimal();
}