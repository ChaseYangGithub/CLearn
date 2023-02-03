#include"boss.h"
//老板类

//构造函数
Boss::Boss(int id, std::string name, int dId) {
	this->id = id;
	this->name = name;
	this->deptId = dId;
}

//显示个人信息
 void Boss::showInfo() {
	 std::cout << "职工编号：" << this->id
		 << "\t职工姓名：" << this->name
		 << "\t岗位：" << this->getDeptName()
		 << "\t岗位职责：管理公司所有事务" << std::endl;
}
 
 //获取职位信息
 std::string Boss::getDeptName() {
	 return std::string("总裁");
 }