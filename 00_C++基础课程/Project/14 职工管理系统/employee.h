#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "worker.h"
//��ͨԱ����
class Employee:public Worker {
public:
	//���캯��
	Employee(int id, std::string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();//������д
	//��ȡְ����λ����
	virtual std::string getDeptName();//������д
};
#endif