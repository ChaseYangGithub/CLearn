#include<iostream>
using namespace std;
/*
常函数：
	成员函数后加const后我们称为这个函数为 常函数 类似： void testJack() const{}
	常函数内不可以修改成员属性
	成员属性声明时加关键字mutable后，在常函数中依然可以修改
常对象：
	声明对象前加const称该对象为常对象
	常对象只能调用常函数
*/

//夹克类
class Jack {
public:
	Jack() {
		a = 1;
		b = 0;
	}
	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	void  showJack() const {
		// const Type* const pointer;
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->a = 100; //但是this指针指向的对象的数据是可以修改的

		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->b = 100;
	}
	void funcJack() {
		a = 1000;
	}
public:
	int a;
	mutable int b;//可修改，可变的
};


//const修饰对象  常对象
void testConst() {

	const Jack p; //常量对象  
	cout << p.a << endl;
	//p.a = 100; //常对象不能修改成员变量的值,但是可以访问
	p.b = 100; //但是常对象可以修改mutable修饰成员变量

	//常对象访问成员函数
	//p.funcJack(); //常对象不能调用const的函数

}
