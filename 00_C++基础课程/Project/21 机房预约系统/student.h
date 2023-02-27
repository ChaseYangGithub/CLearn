#ifndef STUDENT
#define STUDENT
#include<iostream>
#include<vector>
#include "human.h"//继承基类需要
#include "computer.h"
//学生类
class Student :public Human {
public:
	//默认构造
	Student();
	//有参构造（学号 姓名 密码）
	Student(int id, std::string username, std::string password);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看我的预约
	void showMyApply();
	//查看所有预约
	void showAllApply();
	//取消预约
	void cancleApply();
	//初始化机房信息
	void initComputer();
	//机房满
	bool roomFull(int room);
	//修改机房信息--待定 应该由老师进行
	//void roomChange(int room);
public:
	int id;//学生学号
	std::vector<Computer> sC;//机房
};

#endif