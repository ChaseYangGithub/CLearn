#include<iostream>

//��ģ��
template<class type1, class type2=int>//ָ��type2Ĭ�ϲ���Ϊint
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

void test22() {
	//1 ��ģ��û���Զ����͵��Ƶ���ʽ
	//Person p("����", 12);//������ʹ���Զ��Ƶ�
	Person < std::string, int>  p1("�����", 21);//����ʹ����ʾָ�����͵ķ�ʽ
	p1.showPerson();
	//2 ��ģ����ģ������б��п�����Ĭ�ϲ���
	Person <std::string>p("��˽�", 34);
	p.showPerson();
}