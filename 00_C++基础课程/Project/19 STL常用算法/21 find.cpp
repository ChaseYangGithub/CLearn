#include<iostream>
#include<vector>
#include<algorithm>
class Person {
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
	//����==
	bool operator==(const Person& p) {
		if (this->name ==p.name && this->age ==p.age) {
			return true;
		}
		return false;
	}
public:
	std::string name;//����
	int age;	//����
};
//find ��ֵ����Ԫ��
void test21() {
	//������������
	std::vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i + 1);
	}
	//�����������Ƿ���5���Ԫ��
	std::vector<int>::iterator it = std::find(v.begin(), v.end(), 5);
	//�ж�
	if (it == v.end()) {
		std::cout << "û���ҵ���" << std::endl;
	}
	else {
		std::cout << "�ҵ���" << *it << std::endl;
	}
	//�Զ�����������
	std::vector<Person> v2;
	//��������
	Person p1("baa", 10);
	Person p2("aba", 20);
	Person p3("aab", 30);
	Person p4("baa", 40);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);

	std::vector<Person>::const_iterator is = std::find(v2.begin(), v2.end(), p2);
	if (is == v2.end()) {
		std::cout << "û���ҵ�" << std::endl;
	}
	else {
		std::cout << "�ҵ�������" << is->name << " ���䣺" << is->age << std::endl;
	}
}
