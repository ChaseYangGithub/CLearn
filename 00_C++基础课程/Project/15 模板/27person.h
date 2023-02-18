#ifndef	PERSON
#define PERSON
#include<iostream>

template<class T1,class T2>
class Person {
public:
	Person(T1 name, T2 age);
	void showPerson();
public:
	T1 name;
	T2 age;
};

////构造函数 类外实现
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//	this->name = name;
//	this->age = age;
//}
//
////成员函数 类外实现
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//	std::cout << "姓名: " << this->name << " 年龄:" << this->age << std::endl;
//}
#endif // person
