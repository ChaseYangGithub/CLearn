#include<iostream>

//������
template<class T1, class T2> class Person;

//��������  ���д�˺���ģ�壬���Խ�ʵ��д������ ĳ����Ҫ��ʵ��д�����ǰ���ñ���������
//template<class T1, class T2>void printPerson4(Person<T1, T2>& p);

template<class T1,class T2>
void printPerson4(Person<T1,T2> & p) {
	std::cout << "������" << p.age << " ���䣺" << p.age << std::endl;
}

template<class T1,class T2>
class Person {
	//ȫ�ֺ��������Ԫ������ʵ��
	friend void printPerson(Person<T1, T2>& p) {
		std::cout << "������" << p.name << "���䣺" << p.age << std::endl;
	}

	//ȫ�ֺ�������ʵ��
	friend void printPerson4<>(Person<T1, T2>& p);

public:
	Person(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
public:
	T1 name;
	T2 age;
};

void test28() {
	Person <std::string, int> p("����", 15);
	printPerson(p);
	Person <std::string, int> p2("����", 15);
	printPerson4(p2);
}