#include<iostream>
//��ģ��ͺ���ģ���﷨���ƣ�������ģ��template������࣬�����Ϊ��ģ��

//��ģ��
template<class type1,class type2>
class Person {
public:
	Person(type1 name, type2 age) {
		this->name = name;
		this->age = age;
	}
	void showPerson() {
		std::cout << "name:" << this->name << " age:" << this->age << std::endl;
	}
public:
	type1 name;
	type2 age;
};

void test21() {
	//ָ��type1Ϊstring type2Ϊint
	Person < std::string, int>  p1("�����", 21);
	p1.showPerson();
}