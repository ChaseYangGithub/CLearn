#ifndef STUDENT
#define STUDENT
#include<iostream>
#include<vector>
#include "human.h"//�̳л�����Ҫ
#include "computer.h"
//ѧ����
class Student :public Human {
public:
	//Ĭ�Ϲ���
	Student();
	//�вι��죨ѧ�� ���� ���룩
	Student(int id, std::string username, std::string password);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showMyApply();
	//�鿴����ԤԼ
	void showAllApply();
	//ȡ��ԤԼ
	void cancleApply();
	//��ʼ��������Ϣ
	void initComputer();
	//������
	bool roomFull(int room);
	//�޸Ļ�����Ϣ--���� Ӧ������ʦ����
	//void roomChange(int room);
public:
	int id;//ѧ��ѧ��
	std::vector<Computer> sC;//����
};

#endif