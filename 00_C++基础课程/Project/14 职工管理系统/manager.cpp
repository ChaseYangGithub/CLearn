#include "manager.h"
//经理类

//构造函数
Manager::Manager(int id, std::string name, int dId) {
	this->id = id;
	this->name = name;
	this->deptId = dId;
}

//显示个人信息
void Manager::showInfo() {
	std::cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成老板交代的任务，下发任务给员工" << std::endl;
}

//获取岗位信息
std::string Manager::getDeptName() {
	return std::string("经理");
}