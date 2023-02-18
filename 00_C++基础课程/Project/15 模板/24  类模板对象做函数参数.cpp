#include<iostream>
template<class NameType,class AgeType=int>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}
	void showPerson() {
		std::cout << "name:" << this->name << "age:" << this->age << std::endl;
	}
public:
	NameType name;
	AgeType age;
};

//1 指定传入的数据类型
void printPerson1(Person<std::string, int>& p) {
	p.showPerson();
}

//参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p) {
	p.showPerson();
	std::cout << "T1的数据类型为:" <<typeid(T1).name() << std::endl;
	std::cout << "T2的数据类型为:" <<typeid(T2).name() << std::endl;
}

//整个类模板化
template<class T>
void printPerson3(T& p) {
	std::cout << "T的类型为：" << typeid(T).name() << std::endl;
	p.showPerson();
}

void test24() {
	Person<std::string, int> p("孙悟空", 100);
	printPerson1(p);
	Person<std::string, int> p2("猪八戒", 80);
	printPerson2(p2);
	Person<std::string, int> p3("唐三藏", 60);
	printPerson3(p3);

}