#include<iostream>
#include "27person.h"
/*
* 
���⣺��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���

ע�⣺����`VS2022ƽ̨` `C+ + 14 ` `WinSDK10`
* **����ʵ�� * *����ʵ����cpp
* **����ʵ�� * *��������ʵ��ȫ����.h�ļ���
* **����ʵ�� * *#include "person.cpp" ��������`person.cpp`ʵ�ֺ���ʵ�֣�ʵ���а���cppԴ�ļ�
* **����ʵ�� * *��������ʵ��д��һ���ļ���׺����cpp�ļ������ø�Ϊ.hpp

*/


//���캯�� ����ʵ��
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

//��Ա���� ����ʵ��
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	std::cout << "����: " << this->name << " ����:" << this->age << std::endl;
}
void test27() {
	Person<std::string, int> p("����", 21);
	p.showPerson();	
}