#include<iostream>
#include<set>

class Person {
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
public:
	std::string name;//����
	int age;//����
};

class MyCompare {
public:
	//�ݼ�˳��
	bool operator()(int v1, int v2) const {//ע��VSϵ����Ҫ���º���д�ɳ���������ʽ����Ҫ����const�����򱨴�C3848����ͬ
		return v1 > v2;
	}
};
class ComparePerson {
public:
	//�������併��
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
	//Ĭ�ϴ�С��������
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	//ָ���������
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

	//�Զ�����������
	std::set<Person, ComparePerson> s3;
	Person p1("����", 23);
	Person p2("����", 27);
	Person p3("�ŷ�", 25);
	Person p4("����", 21);
	s3.insert(p1);
	s3.insert(p2);
	s3.insert(p3);
	s3.insert(p4);
	for (std::set<Person, ComparePerson>::iterator it = s3.begin(); it != s3.end(); it++)
	{
		std::cout << "������ " << it->name << " ���䣺 " << it->age << std::endl;
	}
}
