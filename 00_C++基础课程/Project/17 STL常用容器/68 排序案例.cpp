#include<iostream>
#include<list>
/*
案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高

排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
*/


class Person2 {
public:
	Person2(std::string name, int age, int height) {
		this->name = name;
		this->age = age;
		this->height = height;
	}
public:
	std::string name;//姓名
	int age;	//年龄
	int height;//身高
};

//数据输出
void printPerson(const std::list<Person2>& l) {
	for (std::list<Person2>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << "姓名：" << it->name << " 年龄:" << it->age << "身高:" <<it->height << std::endl;
	}
	std::cout << std::endl;
}
//比较年龄 优先年龄，其次身高
bool comparePerson(Person2& p1, Person2& p2) {
	if (p1.age == p2.age) {
		return p1.height > p2.height;
	}
	else {
		return p1.age > p2.age;
	}
}

void test68() {
	std::list<Person2> l;
	//数据准备
	Person2 p1("刘备",25,175);
	Person2 p2("曹操", 45,180);
	Person2 p3("孙权", 40, 170);
	Person2 p4("赵云", 25, 175);
	Person2 p5("关羽", 35, 200);
	//数据录入
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	printPerson(l);//如果你在其他文件中定义了相同的Person类，在容器输出时身高会是乱码（前面的类相对本文件的少个身高的情况下），而Person输出无误
	l.sort(comparePerson);//排序
	printPerson(l);

}