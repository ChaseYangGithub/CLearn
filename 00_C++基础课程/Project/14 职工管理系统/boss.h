#ifndef	BOSS_H
#define BOSS_H
#include"worker.h"
//�ϰ���
class Boss :public Worker {
public:
	//���캯��
	Boss(int id, std::string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡְλ��Ϣ
	virtual std::string getDeptName();
};
#endif