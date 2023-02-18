#include<iostream>
//类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板

//类模板
template<class type1,class type2>
class Person {
public:
	Person(type1 name, type2 age) {
		this->name = name;
		this->age = age;
	}
	void showPerson() {
		std::cout << "name:" << this->name << " age:" << this->age << std::endl;
	}
public:
	type1 name;
	type2 age;
};

void test21() {
	//指定type1为string type2为int
	Person < std::string, int>  p1("刘亦菲", 21);
	p1.showPerson();
}