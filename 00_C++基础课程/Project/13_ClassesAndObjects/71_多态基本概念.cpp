#include<iostream>
using namespace std;
//多态基本概念

//动物类
class Zoon {
public:
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	virtual void speak() {
		cout << "动物说话" << endl;
	}
};
//猫类
class Cat :public Zoon {
public:
	void speak() {
		cout << "猫说话" << endl;
	}
};
//狗类
class Dog :public Zoon {
public:
	void speak() {
		cout << "狗说话" << endl;
	}
};
//执行说话
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编
void doSpeak(Zoon& zoon) {	// Zoon &zoon =	cat; 父类的引用或者指针指向子类的对象
	zoon.speak();
}
//多态满足条件： 
//1、有继承关系 
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象
void multyTest() {
	Cat cat;
	doSpeak(cat);
	Zoon zoon;
	doSpeak(zoon);
}
//重写：函数返回值类型  函数名 参数列表 完全一致称为重写