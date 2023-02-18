#include<iostream>
#include<vector>
#include<algorithm>
class Person2 {
public:
	Person2(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	//����==
	bool operator==(const Person2& p) {
		if (this->name == p.name && this->age == p.age) {
			return true;
		}
		return false;
	}
public:
	std::string name;//����
	int age;	//����
};
//������������
class GreateFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
//�Զ�����������
class GreateFive2 {
public:
	bool operator()(Person2& p) {
		return p.age > 20;
	}
};
//find_if����ָ��Ԫ��
void test22() {
	//������������
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), GreateFive());
	if (it == v.end()) {
		std::cout << "δ�ҵ�" << std::endl;
	}
	else {
		std::cout << "�ҵ�����5�����ݣ�" << *it << std::endl;
	}
	//�Զ�����������
	std::vector<Person2> v2;
	//׼������
	Person2 p1("cbbb", 13);
	Person2 p2("bcbb", 71);
	Person2 p3("bbcb", 12);
	Person2 p4("bbbc", 63);
	Person2 p5("bbbb", 14);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	std::vector<Person2>::iterator as = std::find_if(v2.begin(), v2.end(), GreateFive2());
	if (as == v2.end()) {
		std::cout << "δ�ҵ�" << std::endl;
	}
	else {
		std::cout << "�ҵ�������" << as->name <<" ���䣺"<<as->age<< std::endl;
	}
}