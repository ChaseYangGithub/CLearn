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

////���캯�� ����ʵ��
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//	this->name = name;
//	this->age = age;
//}
//
////��Ա���� ����ʵ��
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//	std::cout << "����: " << this->name << " ����:" << this->age << std::endl;
//}
#endif // person
