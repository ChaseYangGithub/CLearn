#include<iostream>
#include<list>
/*
������������Person�Զ����������ͽ�������Person�����������������䡢���

������򣺰�����������������������ͬ������߽��н���
*/


class Person2 {
public:
	Person2(std::string name, int age, int height) {
		this->name = name;
		this->age = age;
		this->height = height;
	}
public:
	std::string name;//����
	int age;	//����
	int height;//���
};

//�������
void printPerson(const std::list<Person2>& l) {
	for (std::list<Person2>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << "������" << it->name << " ����:" << it->age << "���:" <<it->height << std::endl;
	}
	std::cout << std::endl;
}
//�Ƚ����� �������䣬������
bool comparePerson(Person2& p1, Person2& p2) {
	if (p1.age == p2.age) {
		return p1.height > p2.height;
	}
	else {
		return p1.age > p2.age;
	}
}

void test68() {
	std::list<Person2> l;
	//����׼��
	Person2 p1("����",25,175);
	Person2 p2("�ܲ�", 45,180);
	Person2 p3("��Ȩ", 40, 170);
	Person2 p4("����", 25, 175);
	Person2 p5("����", 35, 200);
	//����¼��
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	printPerson(l);//������������ļ��ж�������ͬ��Person�࣬���������ʱ��߻������루ǰ�������Ա��ļ����ٸ���ߵ�����£�����Person�������
	l.sort(comparePerson);//����
	printPerson(l);

}