#include<iostream>
#include<vector>
#include<algorithm>
class Person {
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	//重载==
	bool operator==(const Person& p) {
		if (this->name ==p.name && this->age ==p.age) {
			return true;
		}
		return false;
	}
public:
	std::string name;//姓名
	int age;	//年龄
};
//find 按值查找元素
void test21() {
	//基本数据类型
	std::vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i + 1);
	}
	//查找容器中是否有5这个元素
	std::vector<int>::iterator it = std::find(v.begin(), v.end(), 5);
	//判定
	if (it == v.end()) {
		std::cout << "没有找到！" << std::endl;
	}
	else {
		std::cout << "找到：" << *it << std::endl;
	}
	//自定义数据类型
	std::vector<Person> v2;
	//创建数据
	Person p1("baa", 10);
	Person p2("aba", 20);
	Person p3("aab", 30);
	Person p4("baa", 40);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);

	std::vector<Person>::const_iterator is = std::find(v2.begin(), v2.end(), p2);
	if (is == v2.end()) {
		std::cout << "没有找到" << std::endl;
	}
	else {
		std::cout << "找到姓名：" << is->name << " 年龄：" << is->age << std::endl;
	}
}
