#include<iostream>
#include<set>

class Person {
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
public:
	std::string name;//姓名
	int age;//年龄
};

class MyCompare {
public:
	//递减顺序
	bool operator()(int v1, int v2) const {//注意VS系列需要将仿函数写成常函数的形式，即要加上const，否则报错C3848。下同
		return v1 > v2;
	}
};
class ComparePerson {
public:
	//按照年龄降序
	bool operator()(const Person& p1, const Person& p2) const {
		return p1.age > p2.age;
	}
};

void test78() {
	std::set<int> s;
	s.insert(10);
	s.insert(17);
	s.insert(15);
	s.insert(3);
	s.insert(18);
	//默认从小到大排序
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	//指定排序规则
	std::set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);
	for (std::set<int, MyCompare>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	//自定义数据类型
	std::set<Person, ComparePerson> s3;
	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
	s3.insert(p1);
	s3.insert(p2);
	s3.insert(p3);
	s3.insert(p4);
	for (std::set<Person, ComparePerson>::iterator it = s3.begin(); it != s3.end(); it++)
	{
		std::cout << "姓名： " << it->name << " 年龄： " << it->age << std::endl;
	}
}
