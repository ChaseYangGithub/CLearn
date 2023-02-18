#include<iostream>

//person��
class Person {
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	std::string name;
	int age;
};

//��ͨģ�庯��ʵ�ֶԱ�
template<class T>
bool myCompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

//���廯����ʾ���廯��ԭ�ͺ��ض�������˼��template<>��ͷ����ͨ��ָ����ָ��
//���廯���ڳ���ģ��
template<> bool myCompare(Person& p1, Person& p2) {
	if (p1.name == p2.name && p1.age == p2.age) {
		return true;
	}
	else {
		return false;
	}
}

void test16() {
	Person p1("Tom", 16);
	Person p2("katty", 12);
	//�Զ����������Ͳ��������ͨģ�庯��
	//���Դ������廯��Person��������ģ�壬���ڴ����ض��������͵�
	bool ans = myCompare(p1, p2);
	if (ans) {
		std::cout << "p1==p2" << std::endl;
	}
	else {
		std::cout << "p1!=p2" << std::endl;
	}
}
//ѧϰģ�岻��Ϊ��дģ�壬��������STL���ܹ�����ϵͳ�ṩ��ģ��