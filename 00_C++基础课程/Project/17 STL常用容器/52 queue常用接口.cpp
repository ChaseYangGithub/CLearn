#include<iostream>
#include<queue>
//#include<string>

class Person {
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;
	}
public:
	std::string name;
	int age;
};

void test52() {
	//��������
	std::queue<Person> q;
	//׼������
	Person p1("��ɮ", 30);
	Person p2("�����", 1000);
	Person p3("��˽�", 900);
	Person p4("ɳɮ", 800);
	//��������������
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	//���в��ṩ������������֧���������
	while (!q.empty()) {
		//�����ͷԪ��
		std::cout << "��ͷԪ��-������" << q.front().name
			<< " ���䣺" << q.front().age << std::endl;
		//�����βԪ��
		std::cout << "��βԪ��-����:" << q.back().name
			<< " ���䣺" << q.back().age << std::endl;
		//������ͷԪ��
		q.pop();
	}
	std::cout << "���д�СΪ��" << q.size() << std::endl;
}