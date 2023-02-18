#include<iostream>
#include<vector>
#include<algorithm>
class Person2 {
public:
	Person2(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	//重载==
	bool operator==(const Person2& p) {
		if (this->name == p.name && this->age == p.age) {
			return true;
		}
		return false;
	}
public:
	std::string name;//姓名
	int age;	//年龄
};
//内置数据类型
class GreateFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
//自定义数据类型
class GreateFive2 {
public:
	bool operator()(Person2& p) {
		return p.age > 20;
	}
};
//find_if查找指定元素
void test22() {
	//基本数据类型
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), GreateFive());
	if (it == v.end()) {
		std::cout << "未找到" << std::endl;
	}
	else {
		std::cout << "找到大于5的数据：" << *it << std::endl;
	}
	//自定义数据类型
	std::vector<Person2> v2;
	//准备数据
	Person2 p1("cbbb", 13);
	Person2 p2("bcbb", 71);
	Person2 p3("bbcb", 12);
	Person2 p4("bbbc", 63);
	Person2 p5("bbbb", 14);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	std::vector<Person2>::iterator as = std::find_if(v2.begin(), v2.end(), GreateFive2());
	if (as == v2.end()) {
		std::cout << "未找到" << std::endl;
	}
	else {
		std::cout << "找到姓名：" << as->name <<" 年龄："<<as->age<< std::endl;
	}
}