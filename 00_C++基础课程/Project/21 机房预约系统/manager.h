#ifndef	MANAGER
#define MANAGER
#include<iostream>
#include<vector>	//����
#include "student.h"
#include "teacher.h"
#include "human.h"
#include "computer.h"
//����Ա��
class Manager :public Human {
public:
	//Ĭ�Ϲ��캯��
	Manager();
	//�вι��캯��
	Manager(std::string username, std::string password);
	//��ʾ����Ա�����˵�
	void operMenu();
	//����˺�
	void addAccount();
	//��ʾ�˺�
	void showAccount();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void clearRecord();
	//��ʼ������
	void initVector();
	//����ظ� ���  ���� 1 ��ʦ 2ѧ��
	bool checkRepeat(int id,int type);
	//��ʼ��������Ϣ
	void initComputer();
public:
	std::vector<Student> sV;//ѧ��
	std::vector<Teacher> tV;//��ʦ
	std::vector<Computer> cV;//����
};
#endif