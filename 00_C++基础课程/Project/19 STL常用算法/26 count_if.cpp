#include<iostream>
#include<vector>
#include<algorithm>
//��������
class Greate4 {
public:
	bool operator()(int val) {
		return val > 1;
	}
};
//�Զ�����
class Person4 {
public:
	Person4(std::string name, int age) {
		this->name = name;
		this->age = age;
	}

public:
	std::string name;//����
	int age;//����
};
//�����������
class AgeLess {
public:
	bool operator()(const Person4& p) {
		return p.age > 1;
	}
};
//ͳ��Ԫ�ظ���
void test26() {
	//������������
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	int num = std::count_if(v.begin(), v.end(), Greate4());
	std::cout << "����1�ĸ���Ϊ��" << num << std::endl;
	//�Զ�����������
	std::vector<Person4> v2;
	Person4 p1("121", 1);
	Person4 p2("121", 3);
	Person4 p3("131", 2);
	Person4 p4("121", 2);
	Person4 p5("131", 1);
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);
	Person4 p("121", 1);
	int num2 = std::count_if(v2.begin(), v2.end(), AgeLess());
	std::cout << "�ҵ��������1����Ϊ��" << num2 << std::endl;
}