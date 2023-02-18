#include<iostream>

//类模板中成员函数的创建时机
//普通类中的成员函数一开始就可以创建
//类模板中的成员函数在调用时才创建

class Person1 {
public:
	void showPerson1() {
		std::cout << "显示person1" << std::endl;
	}
};

class Person2 {
public:
	void showPerson2() {
		std::cout << "显示Person2" << std::endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;
	//类模板中的函数并不是一开始就创建的，而是在模板调用时再生成

	void func1() {
		obj.showPerson1();
	}
	void func2() {
		obj.showPerson2();
	}
};

void test23() {
	MyClass<Person1> m;
	m.func1();
	//m.func2();//编译出错，说明函数调用才会去创建成员函数
}