#ifndef WORK_H
#define WORK_H	
#include<iostream>
//ְ���������
class Worker {
public:
	//��ʾְλ��Ϣ
	virtual void showInfo() = 0;//����������
	//��ȡ��λ����
	virtual std::string getDeptName() = 0;
public:
	int id;//ְ�����
	std::string name;//ְ������
	int deptId;//ְ�����ڲ��ű��
};
#endif
