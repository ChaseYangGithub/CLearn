#ifndef TEACHER 
#define TEACHER
#include "human.h"
#include<iostream>
//教师类
class Teacher :public Human {
public:
	//默认构造函数
	Teacher();
	//有参构造函数
	Teacher(int id, std::string name, std::string password);
	//显示教师操作菜单
	virtual void operMenu();
	//显示所有预约
	void showAllApply();
	//审核预约
	void reviewApply();
public:
	int id;//教师编号
};
#endif