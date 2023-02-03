#ifndef MANAGER_H
#define MANAGER_H
#include "worker.h"
//经理类
class Manager :public Worker {
public:
	//构造函数
	Manager(int id, std::string name, int dId);
	//显示个人信息
	virtual void showInfo();
	//获取职工岗位名称
	virtual std::string getDeptName();
};
#endif