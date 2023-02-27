#include<iostream>
#include<vector>
#include "teacher.h"
#include "order.h"
//默认构造函数
Teacher::Teacher() {
	id = -1;
}
//有参构造函数
Teacher::Teacher(int id, std::string name, std::string password) {
	this->id = id;
	this->username = name;
	this->password = password;
}
//教师操作菜单
void Teacher::operMenu() {
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "\t\t|\t1 查看所有预约\t|" << std::endl;
	std::cout << "\t\t|\t2 审核预约\t|" << std::endl;
	std::cout << "\t\t|\t0 注销登录\t|" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "请输入功能选项：";
}
//显示所有预约
void Teacher::showAllApply() {
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
//审核预约
void Teacher::reviewApply() {
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
		if (o.data[i]["状态："] == "1") {//可以审核预约的内容
			v.push_back(i);
			std::cout << ++index;
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
			mes += " 状态：审核中";
			std::cout << mes << std::endl;
		}
	}
	//选择
	int choice = 0;
	int ans = 1;
	bool state = true;
	while (state) {
		std::cout << "请输入需要取消预约的序号,0返回：";
		std::cin >> choice;
		if (choice >= 0 && choice <= index) {//合法选择
			if (choice == 0) {//退出审核
				break;
			}
			else {
				//修改数据
				while (true) {//审核当前数据
					std::cout << "2 通过\n 1 不通过\n0 返回\n请输入：";
					std::cin >> ans;
					if (ans == 0 || ans ==1 || ans == 2) {
						if (ans == 0) {//取消审核当前数据
							break;
						}
						else if (ans == 2) {
							o.data[v[choice - 1]]["状态："] = "2";//vector序号从0 选择从1
						}else{
							o.data[v[choice - 1]]["状态："] ="-1";
						}
						o.UpdateOrder();
						system("cls");
						std::cout << "已完成审批！" << std::endl;
						state = false;
						break;
					}
				}

			}
		}
		if (state) {
			system("cls");
			std::cout << "输入不合法！" << std::endl;
		}
		system("pause");
		system("cls");
	}
}