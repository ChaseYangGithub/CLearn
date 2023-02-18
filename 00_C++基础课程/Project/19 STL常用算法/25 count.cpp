#include<iostream>
#include<vector>
#include<algorithm>
class Person3 {
public:
	Person3(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	bool operator==(const Person3& p){
		if (this->age == p.age){
			return true;
		}
		else{
			return false;
		}
	}
public:
	std::string name;//姓名
	int age;//年龄
};
//统计元素个数
void test25() {
	//内置数据类型
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	int num = std::count(v.begin(),v.end(), 1);
	std::cout << "1的个数为：" << num << std::endl;
	//自定义数据类型
	std::vector<Person3> v2;
	Person3 p1("121", 1);
	Person3 p2("121", 3);
	Person3 p3("131", 2);
	Person3 p4("121", 2);
	Person3 p5("131", 1);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	Person3 p("121", 3);
	int num2 = std::count(v2.begin(), v2.end(), p);
	std::cout << "找到p个数为：" << num2 << std::endl;
}