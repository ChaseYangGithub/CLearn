#include "employee.h"
//职工类

//构造函数
Employee::Employee(int id, std::string name, int dId) {
	this->id = id;
	this->name = name;
	this->deptId = dId;
}

//显示个人信息
void Employee::showInfo() {
	std::cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交代的任务" << std::endl;
}

//获取岗位名称
std::string Employee::getDeptName() {
	return std::string("员工");
}