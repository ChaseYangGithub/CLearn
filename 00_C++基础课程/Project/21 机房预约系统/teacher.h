#ifndef TEACHER 
#define TEACHER
#include "human.h"
#include<iostream>
//��ʦ��
class Teacher :public Human {
public:
	//Ĭ�Ϲ��캯��
	Teacher();
	//�вι��캯��
	Teacher(int id, std::string name, std::string password);
	//��ʾ��ʦ�����˵�
	virtual void operMenu();
	//��ʾ����ԤԼ
	void showAllApply();
	//���ԤԼ
	void reviewApply();
public:
	int id;//��ʦ���
};
#endif