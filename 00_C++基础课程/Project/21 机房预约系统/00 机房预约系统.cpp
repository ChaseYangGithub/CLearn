#include<iostream>
#include "00 机房预约系统.h"
#include "globalFile.h"//文件
#include "human.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include<fstream>



int main() {
	int select = -1;//默认重新选择程序
	while (true) {
		main_Menu();//弹出登陆菜单选项
		std::cin >> select;
		switch (select) {
		case 1://学生登陆
			loginIn(STUDENT_FILE, 1);
			break;
		case 2://教师登录
			loginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员登陆
			loginIn(ADMIN_FILE, 3);
			break;
		case 0://退出程序
			system("cls");
			std::cout << "欢迎下次使用！" << std::endl;
			system("pause");
			return 0;
			break;
		default://默认循环
			std::cout << "请重新输入选项！" << std::endl;
			system("pause");
			system("cls");
			break;
		}

	}
	return 0;
}
//教职工子菜单
void teacherMenu(Human*& teacher) {
	int select = -1;
	Teacher* man;
	while (true) {
		//教师菜单
		teacher->operMenu();
		man = (Teacher*)teacher;
		std::cin >> select;
		switch (select) {
		case 1://查看所有预约
			man->showAllApply();
			break;
		case 2://审核预约
			man->reviewApply();
			break;
		case 0:
			delete man;
			std::cout << "注销成功" << std::endl;
			system("pause");
			system("cls");
			return;//退出此cpp如果使用break退出循环报错,因为删除了man
		default:
			std::cout << "请重新输入选项！" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//学生子菜单
void studentMenu(Human*& student) {
	int select = -1;//默认循环
	Student* man;
	while (true) {
		//学生菜单
		student->operMenu();
		man = (Student*)student;//强转防止调用父类的函数
		std::cin >> select;
		switch (select) {
		case 1://申请预约
			man->applyOrder();
			break;
		case 2://查看个人预约
			man->showMyApply();
			break;
		case 3://查看所有预约
			man->showAllApply();
			break;
		case 4://取消预约
			man->cancleApply();
			break;
		case 0://注销登录
			delete man;
			std::cout << "注销成功" << std::endl;
			system("pause");
			system("cls");
			return;//退出此cpp如果使用break退出循环报错
		default://默认循环
			std::cout << "请重新输入选项！" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
//管理员子菜单
void managerMenu(Human*& manager) {
	int select = -1;//默认循环
	Manager* man;
	while (true) {
		//管理员菜单
		manager->operMenu();
		man = (Manager*)manager;//强转防止调用父类的函数
		std::cin >> select;
		switch (select) {
		case 1://添加账号
			man->addAccount();
			break;
		case 2://查看账号
			man->showAccount();
			break;
		case 3://查看机房
			man->showComputer();
			break;
		case 4://清空预约
			man->clearRecord();
			break;
		case 0://注销登录
			delete man;
			std::cout << "注销成功" << std::endl;
			system("pause");
			system("cls");
			return;//退出此cpp如果使用break退出循环报错
		default://默认循环
			std::cout << "请重新输入选项！" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//登陆函数 按照文件名和登陆类型打开文件执行登陆操作
void loginIn(std::string fileName, int type) {
	Human* p = NULL;
	std::ifstream ifs;//文件流
	ifs.open(fileName, std::ios::in);//读方式打开文件
	//文件不存在
	if (!ifs.is_open()) {
		std::cout << "文件不存在" << std::endl;
		system("pause");
		system("cls");
		ifs.close();
		return;
	}

	int id = -1;//防止未初始化错误
	std::string username;
	std::string pwd;
	//学生教师独有的学号教师号
	if (type == 1) {//学生登陆
		std::cout << "请输入学号：";
		std::cin >> id;
	}
	else if (type == 2) {
		std::cout << "请输入职工号:";
		std::cin >> id;
	}
	//通用输入
	std::cout << "请输入用户名：";
	std::cin >> username;
	std::cout << "请输入密码:";
	std::cin >> pwd;

	//登陆验证
	if (type == 1) {
		//学生登陆验证
		int did;
		std::string duser;
		std::string dpwd;
		while (ifs >> did && ifs >> duser && ifs >> dpwd) {//一次读取三个数据且不为空
			if (did == id && duser == username && dpwd == pwd) {
				//校验成功
				std::cout << "学生" << username << "登陆系统" << std::endl;
				system("pause");
				system("cls");
				p = new Student(id, username, pwd);
				//进入学生登陆页面
				studentMenu(p);
				return;
			}
		}
	}
	else if (type == 2) {
		//教师登陆验证
		int did;
		std::string duser;
		std::string dpwd;
		while (ifs >> did && ifs >> duser && ifs >> dpwd) {//一次读取三个数据且不为空
			if (did == id && duser == username && dpwd == pwd) {
				//校验成功
				std::cout << "教师" << username << "登陆系统" << std::endl;
				system("pause");
				system("cls");
				p = new Teacher(id, username, pwd);
				//进入教师登陆页面
				teacherMenu(p);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员登陆验证
		std::string duser;
		std::string dpwd;
		while (ifs >> duser && ifs >> dpwd) {//一次读取三个数据且不为空
			if (duser == username && dpwd == pwd) {
				//校验成功
				std::cout << "管理员" << username << "登陆系统" << std::endl;
				system("pause");
				system("cls");
				p = new Manager(username, pwd);
				//进入管理员子菜单
				managerMenu(p);
				return;
			}
		}
	}
	std::cout << "登陆验证失败，请检查账户或者密码！" << std::endl;
	system("pause");
	system("cls");
	return;

}

//主程序菜单
void main_Menu() {
	std::cout << "==================欢迎登陆机房预约系统===========" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "\t\t|\t1 学生登陆\t|" << std::endl;
	std::cout << "\t\t|\t2 教师登陆\t|" << std::endl;
	std::cout << "\t\t|\t3 管理员登陆\t|" << std::endl;
	std::cout << "\t\t|\t0 退出系统\t|" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "请输入登陆选项：";
}