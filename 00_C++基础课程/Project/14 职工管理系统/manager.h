#ifndef MANAGER_H
#define MANAGER_H
#include "worker.h"
//������
class Manager :public Worker {
public:
	//���캯��
	Manager(int id, std::string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡְ����λ����
	virtual std::string getDeptName();
};
#endif