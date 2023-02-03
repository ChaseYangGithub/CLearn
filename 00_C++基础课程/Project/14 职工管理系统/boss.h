#ifndef	BOSS_H
#define BOSS_H
#include"worker.h"
//老板类
class Boss :public Worker {
public:
	//构造函数
	Boss(int id, std::string name, int dId);
	//显示个人信息
	virtual void showInfo();
	//获取职位信息
	virtual std::string getDeptName();
};
#endif