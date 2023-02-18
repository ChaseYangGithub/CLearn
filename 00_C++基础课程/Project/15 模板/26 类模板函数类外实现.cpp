#include<iostream>

//类模板函数类外实现
template<class T1,class T2>
class Person {
public:
	//成员函数内部声明
	Person(T1 name, T2 age);
	void showPerson();
public:
	T1 name;
	T2 age;
};

//构造函数类外实现
template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

//成员函数类外实现
template<class T1,class T2>
void Person<T1, T2>::showPerson() {
	std::cout << "姓名：" << this->name << " 年龄：" << this->age << std::endl;
}

void test26() {
	Person<std::string, int> p("张师傅", 32);
	p.showPerson();
}