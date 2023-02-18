#include<iostream>

//类模板
template<class type1, class type2=int>//指定type2默认参数为int
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

void test22() {
	//1 类模板没有自动类型的推导方式
	//Person p("张三", 12);//不可以使用自动推导
	Person < std::string, int>  p1("刘亦菲", 21);//必须使用显示指定类型的方式
	p1.showPerson();
	//2 类模板在模板参数列表中可以有默认参数
	Person <std::string>p("猪八戒", 34);
	p.showPerson();
}