#ifndef WORK_H
#define WORK_H	
#include<iostream>
//职工抽象基类
class Worker {
public:
	//显示职位信息
	virtual void showInfo() = 0;//纯虚数函数
	//获取岗位名称
	virtual std::string getDeptName() = 0;
public:
	int id;//职工编号
	std::string name;//职工姓名
	int deptId;//职工所在部门编号
};
#endif
