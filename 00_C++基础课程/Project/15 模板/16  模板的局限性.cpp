#include<iostream>

//person类
class Person {
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	std::string name;
	int age;
};

//普通模板函数实现对比
template<class T>
bool myCompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

//具体化，显示具体化的原型和特定含义意思以template<>开头，并通过指定名指出
//具体化由于常规模板
template<> bool myCompare(Person& p1, Person& p2) {
	if (p1.name == p2.name && p1.age == p2.age) {
		return true;
	}
	else {
		return false;
	}
}

void test16() {
	Person p1("Tom", 16);
	Person p2("katty", 12);
	//自定义数据类型不会调用普通模板函数
	//可以创建具体化的Person数据类型模板，用于处理特定数据类型的
	bool ans = myCompare(p1, p2);
	if (ans) {
		std::cout << "p1==p2" << std::endl;
	}
	else {
		std::cout << "p1!=p2" << std::endl;
	}
}
//学习模板不是为了写模板，而是在在STL上能够运用系统提供的模板