#include<iostream>

//类声明
template<class T1, class T2> class Person;

//函数声明  如果写了函数模板，可以将实现写到后面 某则需要将实现写到类的前面让编译器看到
//template<class T1, class T2>void printPerson4(Person<T1, T2>& p);

template<class T1,class T2>
void printPerson4(Person<T1,T2> & p) {
	std::cout << "姓名：" << p.age << " 年龄：" << p.age << std::endl;
}

template<class T1,class T2>
class Person {
	//全局函数配合友元，类内实现
	friend void printPerson(Person<T1, T2>& p) {
		std::cout << "姓名：" << p.name << "年龄：" << p.age << std::endl;
	}

	//全局函数类外实现
	friend void printPerson4<>(Person<T1, T2>& p);

public:
	Person(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
public:
	T1 name;
	T2 age;
};

void test28() {
	Person <std::string, int> p("刘星", 15);
	printPerson(p);
	Person <std::string, int> p2("张语", 15);
	printPerson4(p2);
}