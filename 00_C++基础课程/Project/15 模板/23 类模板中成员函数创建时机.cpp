#include<iostream>

//��ģ���г�Ա�����Ĵ���ʱ��
//��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���

class Person1 {
public:
	void showPerson1() {
		std::cout << "��ʾperson1" << std::endl;
	}
};

class Person2 {
public:
	void showPerson2() {
		std::cout << "��ʾPerson2" << std::endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;
	//��ģ���еĺ���������һ��ʼ�ʹ����ģ�������ģ�����ʱ������

	void func1() {
		obj.showPerson1();
	}
	void func2() {
		obj.showPerson2();
	}
};

void test23() {
	MyClass<Person1> m;
	m.func1();
	//m.func2();//�������˵���������òŻ�ȥ������Ա����
}