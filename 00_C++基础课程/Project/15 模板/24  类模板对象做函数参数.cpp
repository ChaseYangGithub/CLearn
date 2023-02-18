#include<iostream>
template<class NameType,class AgeType=int>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}
	void showPerson() {
		std::cout << "name:" << this->name << "age:" << this->age << std::endl;
	}
public:
	NameType name;
	AgeType age;
};

//1 ָ���������������
void printPerson1(Person<std::string, int>& p) {
	p.showPerson();
}

//����ģ�廯
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p) {
	p.showPerson();
	std::cout << "T1����������Ϊ:" <<typeid(T1).name() << std::endl;
	std::cout << "T2����������Ϊ:" <<typeid(T2).name() << std::endl;
}

//������ģ�廯
template<class T>
void printPerson3(T& p) {
	std::cout << "T������Ϊ��" << typeid(T).name() << std::endl;
	p.showPerson();
}

void test24() {
	Person<std::string, int> p("�����", 100);
	printPerson1(p);
	Person<std::string, int> p2("��˽�", 80);
	printPerson2(p2);
	Person<std::string, int> p3("������", 60);
	printPerson3(p3);

}