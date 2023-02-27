#include<iostream>
#include<fstream>
#include<algorithm>//for_each
#include "manager.h"
#include "globalFile.h"

//默认构造函数
Manager::Manager() {

}
//有参构造函数
Manager::Manager(std::string username, std::string password) {
	this->username = username;
	this->password = password;
	//初始化容器
	this->initVector();
	//初始化机房信息
	this->initComputer();
}

//显示管理员操作菜单
void Manager::operMenu() {
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "\t\t|\t1 添加账号\t|" << std::endl;
	std::cout << "\t\t|\t2 查看账号\t|" << std::endl;
	std::cout << "\t\t|\t3 查看机房\t|" << std::endl;
	std::cout << "\t\t|\t4 清空预约\t|" << std::endl;
	std::cout << "\t\t|\t0 注销登录\t|" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "请输入功能选项：";
}

//添加账号
void Manager::addAccount() {
	std::string fileName;//文件类型
	std::string name;
	std::string password;
	std::string pwd;//校验
	bool repeat = true;//重复校验
	std::string errorType;//报错信息
	int id=-1;
	int select=-1;//选择
	//类型选择
	while (true) {
		std::cout << "1 添加老师账号" << std::endl;
		std::cout << "2 添加学生账号" << std::endl;
		std::cout << "请输入添加账号类型：";
		std::cin >> select;
		if (select == 1) {
			fileName = TEACHER_FILE;
			errorType = "职工编号重复,请重新输入：";
			std::cout << "请输入职工编号：";
			break;
		}
		else if (select == 2) {
			fileName = STUDENT_FILE;
			errorType = "学生学号重复，请重新输入：";
			std::cout << "请输入学生学号：";
			break;
		}
	}
	//编号重复
	while (repeat) {
		std::cin >> id;
		repeat = checkRepeat(id, select);
		if (repeat) {
			std::cout << errorType << std::endl;
		}
	}
	
	std::cout << "请输入姓名：";
	std::cin >> username;
	//密码
	while (true) {
		std::cout << "请输入密码:";
		std::cin >> password;
		std::cout << "请再次输入密码:";
		std::cin >> pwd;
		if (password == pwd) {
			break;
		}
		else {
			system("cls");
			std::cout << "两次密码输入不一致，请重新输入！" << std::endl;
		}
	}
	//录入文件
	std::ofstream ofs;
	ofs.open(fileName, std::ios::out | std::ios::app);//写文件 追加方式
	ofs << id << " " << username << " " << password << std::endl;
	std::cout << "添加成功！" << std::endl;
	std::cout << "添加信息："<<id<<" "<<username<<" "<<password << std::endl;
	ofs.close();
	//重新初始化容器
	initVector();
	system("pause");
	system("cls");

}

//通用打印
template<class T>
void printInfo(T& s) {
	std::cout << s.id <<"\t" << s.username<<"\t" << s.password << std::endl;
}
//显示账号
void Manager::showAccount() {
	int select=-1;
	while (true) {
		std::cout << "1 查看所有教师" << std::endl;
		std::cout << "2 查看所有学生" << std::endl;
		std::cout << "请选择查看对象:";
		std::cin >> select;
		if (select != 1 && select != 2) {
			system("cls");
			std::cout << "请重新选择查看对象！"<<std::endl;
		}
		else {
			break;
		}
	}
	if (select == 1) {
		system("cls");
		std::cout << "职工号\t姓名\t密码" << std::endl;
		std::for_each(tV.begin(), tV.end(), printInfo<Teacher>);
	}
	else if (select == 2) {
		system("cls");
		std::cout << "学号\t姓名\t密码" << std::endl;
		std::for_each(sV.begin(), sV.end(), printInfo<Student>);
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer() {
	system("cls");
	std::cout << "机房信息如下："<<std::endl;
	for (std::vector<Computer>::iterator it = cV.begin(); it != cV.end(); it++) {
		std::cout << "编号：" << it->room << "容量：" << it->capacity<<std::endl;
	}
	system("pause");
	system("cls");

}

//清空预约记录
void Manager::clearRecord() {
	//操作文件
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::trunc);//如果存在先删除再创建
	ofs.close();
	std::cout << "清空记录成功！" << std::endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector() {
	//读取数据老师
	std::ifstream ifs;
	//判空
	ifs.open(TEACHER_FILE, std::ios::in);
	if (!ifs.is_open()) {
		std::cout << "初始化容器--文件教师读取失败" << std::endl;
		return;
	}
	//容器置空
	tV.clear();
	Teacher t;
	//读取数据
	while (ifs >> t.id && ifs >> t.username && ifs >> t.password) {
		tV.push_back(t);
	}
	//数据统计
	//std::cout << "当前教师数据为：" << tV.size() << std::endl;
	//关闭文件
	ifs.close();

	//读取数据学生
	ifs.open(STUDENT_FILE, std::ios::in);
	//判空
	if (!ifs.is_open()) {
		std::cout << "初始化容器--文件学生读取失败" << std::endl;
		return;
	}
	//容器置空
	sV.clear();
	//读取数据
	Student s;
	while (ifs >> s.id && ifs >> s.username && ifs >> s.password) {
		sV.push_back(s);
	}
	//数据统计
	//std::cout << "当前学生数据为：" << sV.size() << std::endl;
	//关闭文件
	ifs.close();

}

//检测重复函数
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (std::vector<Teacher>::iterator it = tV.begin(); it != tV.end(); it++) {
			if (id == it->id) {
				return true;
			}
		}
	}
	else if(type==2) {
		for (std::vector<Student>::iterator it = sV.begin(); it != sV.end(); it++) {
			if (id == it->id) {
				return true;
			}
		}
	}
	return false;
}

//初始化机房信息
void Manager::initComputer() {
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	Computer c;
	while (ifs >> c.room && ifs >> c.capacity&&ifs>>c.size) {
		cV.push_back(c);
	}
	//std::cout << "当前机房数量：" << cV.size() << std::endl;
	ifs.close();
}