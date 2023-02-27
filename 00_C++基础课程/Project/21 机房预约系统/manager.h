#ifndef	MANAGER
#define MANAGER
#include<iostream>
#include<vector>	//容器
#include "student.h"
#include "teacher.h"
#include "human.h"
#include "computer.h"
//管理员类
class Manager :public Human {
public:
	//默认构造函数
	Manager();
	//有参构造函数
	Manager(std::string username, std::string password);
	//显示管理员操作菜单
	void operMenu();
	//添加账号
	void addAccount();
	//显示账号
	void showAccount();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void clearRecord();
	//初始化容器
	void initVector();
	//检测重复 编号  类型 1 老师 2学生
	bool checkRepeat(int id,int type);
	//初始化机房信息
	void initComputer();
public:
	std::vector<Student> sV;//学生
	std::vector<Teacher> tV;//教师
	std::vector<Computer> cV;//机房
};
#endif