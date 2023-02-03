#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "worker.h"
//普通员工类
class Employee:public Worker {
public:
	//构造函数
	Employee(int id, std::string name, int dId);
	//显示个人信息
	virtual void showInfo();//必须重写
	//获取职工岗位名称
	virtual std::string getDeptName();//必须重写
};
#endif