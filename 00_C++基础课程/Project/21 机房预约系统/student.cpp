#include<iostream>
#include<fstream>
#include<vector>
#include "student.h"
#include "order.h"
#include "globalFile.h"
//默认构造函数
Student::Student() {
	id = -1;//防止未初始化警告

}
//带参构造函数
Student::Student(int id, std::string name, std::string password) {
	this->id = id;
	this->username = name;
	this->password = password;
	//初始化机房容器
	this->initComputer();
}
//菜单界面
void Student::operMenu() {
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "\t\t|\t1 添加预约\t|" << std::endl;
	std::cout << "\t\t|\t2 查看个人预约\t|" << std::endl;
	std::cout << "\t\t|\t3 查看所有预约\t|" << std::endl;
	std::cout << "\t\t|\t4 取消预约\t|" << std::endl;
	std::cout << "\t\t|\t0 注销登录\t|" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "请输入功能选项：";
}
//申请预约
void Student::applyOrder() {
	int data = 0;//星期
	int intNum = 0;//上下午
	int roomNum = 0;//房间
	//申请日期
	while (true) {
		std::cout << "机房开放时间为周一到周五" << std::endl
			<< "1 周一" << std::endl
			<< "2 周二" << std::endl
			<< "3 周三" << std::endl
			<< "4 周四" << std::endl
			<< "5 周五" << std::endl
			<< "请输入预约的日期:";

		std::cin >> data;
		if (data >= 1 && data <= 5) {
			break;
		}
		system("cls");
		std::cout << "输入有误请重新输入！" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	//申请时间
	while (true) {
		std::cout << "每天时间段如下：" << std::endl
			<< "1 上午" << std::endl
			<< "2 下午" << std::endl
			<< "请输入预约的时间段:";
		std::cin >> intNum;
		if (intNum == 1 || intNum == 2) {
			break;
		}
		system("cls");
		std::cout << "输入有误请重新输入！" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	//申请机房
	while (true) {
		std::cout << "请选择申请的机房!" << std::endl;
		//机房信息
		for (int i = 0; i < sC.size(); i++) {
			std::cout << i + 1 << " "
				<< sC[i].room << "号机房 容量："
				<< sC[i].capacity << " 当前空余："
				<< sC[i].size << std::endl;
		}
		std::cin >> roomNum;
		if (roomNum >= 1 && roomNum <= sC.size() + 1 && !roomFull(roomNum)) {//暂时默认房间号递增
			break;
		}
		system("cls");
		std::cout << "输入有误或者机房满 请重新输入！" << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	//文件载入
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::out | std::ios::app);
	//录入信息
	ofs << "日期：" << data << " "
		<< "代码：" << intNum << " "
		<< "学号：" << this->id << " "
		<< "姓名：" << this->username << " "
		<< "机房：" << roomNum << " "
		<< "状态：" << 1 << std::endl;//假设1 申请 2同意 0取消 -1失败
	ofs.close();
	//更新预约
	Order o;
	o.UpdateOrder();
	system("pause");
	system("cls");
}
//查看个人预约
void Student::showMyApply() {
	Order o;
	//std::cout << o.size;//没问题
	system("cls");
	//对象数据为空
	if (o.size == 0) {
		std::cout << "预约数据为空！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	//对象数据不为空
	for (int i = 0; i < o.size; i++) {
		//std::cout << atoi(o.data[i]["学号："].c_str());
		//数据id比较   c_str()将string转化成字符数据  C中 atoi()将指针指向字符串转化为整数
		if (atoi(o.data[i]["学号："].c_str()) == this->id) {
			std::cout << i + 1;
			std::string mes = "、预约日期：周";
			//预约时间
			switch (atoi(o.data[i]["日期："].c_str())) {
			case 1:
				mes += "一 ";
				break;
			case 2:
				mes += "二 ";
				break;
			case 3:
				mes += "三 ";
				break;
			case 4:
				mes += "四 ";
				break;
			case 5:
				mes += "五 ";
				break;
			}
			//时间段
			mes += (o.data[i]["时间："] == "1" ? "上午 " : "下午 ");
			//学号
			mes += "学号：" + o.data[i]["学号："];
			//姓名
			mes += " 姓名：" + o.data[i]["姓名："];
			//机房
			mes += " 机房：" + o.data[i]["机房："];
			//状态
			mes += " 状态：";
			switch (atoi(o.data[i]["状态："].c_str())) {
			case 1:
				mes += "审核中";
				break;
			case 2:
				mes += "预约成功";
				break;
			case 0:
				mes += "取消预约";
				break;
			case -1:
				mes += "预约失败";
				break;
			}
			std::cout << mes << std::endl;
		}
	}
	system("pause");
	system("cls");
}
//查看所有预约
void Student::showAllApply() {
	Order o;
	//std::cout << o.size;//没问题
	//对象数据为空
	system("cls");
	if (o.size == 0) {
		std::cout << "预约数据为空！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	//对象数据不为空
	for (int i = 0; i < o.size; i++) {
		//std::cout << atoi(o.data[i]["学号："].c_str());
		std::cout << i + 1;
		std::string mes = "、预约日期：周";
		//预约时间
		//数据id比较   c_str()将string转化成字符数据  C中 atoi()将指针指向字符串转化为整数
		switch (atoi(o.data[i]["日期："].c_str())) {
		case 1:
			mes += "一 ";
			break;
		case 2:
			mes += "二 ";
			break;
		case 3:
			mes += "三 ";
			break;
		case 4:
			mes += "四 ";
			break;
		case 5:
			mes += "五 ";
			break;
		}
		//时间段
		mes += (o.data[i]["时间："] == "1" ? "上午 " : "下午 ");
		//学号
		mes += "学号：" + o.data[i]["学号："];
		//姓名
		mes += " 姓名：" + o.data[i]["姓名："];
		//机房
		mes += " 机房：" + o.data[i]["机房："];
		//状态
		mes += " 状态：";
		switch (atoi(o.data[i]["状态："].c_str())) {
		case 1:
			mes += "审核中";
			break;
		case 2:
			mes += "预约成功";
			break;
		case 0:
			mes += "取消预约";
			break;
		case -1:
			mes += "预约失败";
			break;
		}
		std::cout << mes << std::endl;
	}
	system("pause");
	system("cls");
}
//取消预约
void Student::cancleApply() {
	Order o;
	system("cls");
	//对象数据为空
	if (o.size == 0) {
		std::cout << "预约数据为空！" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	int index = 0;
	std::vector<int> v;//记录指定数据的序号
	//对象数据不为空
	for (int i = 0; i < o.size; i++) {
		//数据id比较   c_str()将string转化成字符数据  C中 atoi()将指针指向字符串转化为整数
		if (atoi(o.data[i]["学号："].c_str()) == this->id) {
			if (o.data[i]["状态："] == "1" || o.data[i]["状态："] == "2") {//可以取消预约的内容
				v.push_back(i);
				std::cout << ++index;
				std::string mes = "、预约日期：周";
				//预约时间
				switch (atoi(o.data[i]["日期："].c_str())) {
				case 1:
					mes += "一 ";
					break;
				case 2:
					mes += "二 ";
					break;
				case 3:
					mes += "三 ";
					break;
				case 4:
					mes += "四 ";
					break;
				case 5:
					mes += "五 ";
					break;
				}
				//时间段
				mes += (o.data[i]["时间："] == "1" ? "上午 " : "下午 ");
				//机房
				mes += " 机房：" + o.data[i]["机房："];
				//状态
				mes += " 状态：";
				switch (atoi(o.data[i]["状态："].c_str())) {
				case 1:
					mes += "审核中";
					break;
				case 2:
					mes += "预约成功";
					break;
				}
				std::cout << mes << std::endl;
			}
		}
	}
	//选择
	int choice = 0;
	while (true) {
		std::cout << "请输入需要取消预约的序号,0返回：";
		std::cin >> choice;
		if (choice >= 0 && choice <= index) {
			if (choice == 0) {
				break;
			}
			else {
				//修改数据
				o.data[v[choice-1]]["状态："] = "0";
				o.UpdateOrder();
				std::cout << "已经取消预约" << std::endl;
				break;
			}

		}
		system("cls");
		std::cout << "输入不合法！" << std::endl;
	}

	system("pause");
	system("cls");
}
//初始化机房信息
void Student::initComputer() {
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	Computer c;
	while (ifs >> c.room && ifs >> c.capacity && ifs >> c.size) {
		sC.push_back(c);
	}
	ifs.close();
}

//机房满
bool Student::roomFull(int room) {
	for (std::vector<Computer>::iterator it = sC.begin(); it != sC.end(); it++) {
		if (it->room == room && it->capacity > it->size) {
			return false;
		}
	}
	return true;
}
//修改机房信息
//void Student::roomChange(int room) {
//	std::fstream fs;
//	fs.open(COMPUTER_FILE, std::ios::out | std::ios::app);
//	for (std::vector<Computer>::iterator it = sC.begin(); it != sC.end(); it++) {
//		if (it->room == room && it->capacity > it->size) {
//			return false;
//		}
//	}
//}