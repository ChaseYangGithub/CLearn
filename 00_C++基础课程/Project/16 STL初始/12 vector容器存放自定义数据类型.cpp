#include<iostream>
#include<vector>
#include<algorithm>
//�Զ�����������
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
//��Ŷ���
void test12() {
	std::vector<Person> v;
	//��������
	Person p1("����", 12);
	Person p2("����", 13);
	Person p3("����", 14);
	Person p4("����", 15);
	Person p5("����", 16);
	Person p6("̤ѩ", 17);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "������" << (*it).name << " ���䣺" << (*it).age << std::endl;
	}

	std::vector<Person*> v2;

	//��������
	Person a1("aaa", 10);
	Person a2("bbb", 20);
	Person a3("ccc", 30);
	Person a4("ddd", 40);
	Person a5("eee", 50);
	v2.push_back(&a1);
	v2.push_back(&a2);
	v2.push_back(&a3);
	v2.push_back(&a4);
	v2.push_back(&a5);

	for (std::vector<Person*>::iterator it = v2.begin(); it != v2.end(); it++) {
		Person* p = (*it);
		std::cout << "Name:" << p->name << " Age:" << (*it)->age << std::endl;
	}
}