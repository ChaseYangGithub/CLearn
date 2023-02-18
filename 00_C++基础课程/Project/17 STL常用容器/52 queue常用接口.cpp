#include<iostream>
#include<queue>
//#include<string>

class Person {
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
public:
	std::string name;
	int age;
};

void test52() {
	//创见队列
	std::queue<Person> q;
	//准备数据
	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 900);
	Person p4("沙僧", 800);
	//像队列中添加数据
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	//队列不提供迭代器，更不支持随机访问
	while (!q.empty()) {
		//输出队头元素
		std::cout << "队头元素-姓名：" << q.front().name
			<< " 年龄：" << q.front().age << std::endl;
		//输出队尾元素
		std::cout << "队尾元素-姓名:" << q.back().name
			<< " 年龄：" << q.back().age << std::endl;
		//弹出队头元素
		q.pop();
	}
	std::cout << "队列大小为：" << q.size() << std::endl;
}