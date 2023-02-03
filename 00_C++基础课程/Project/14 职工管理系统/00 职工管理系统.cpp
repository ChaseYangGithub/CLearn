#include<iostream>
#include "workerManager.h"	//职工类
#include"worker.h"			//职工抽象基类
#include"employee.h"		//员工类
#include"manager.h"			//管理类
#include"boss.h"			//老板类
void test();
int main() {
	WorkerManager wm;
	int choice = 0;//功能选择，默认为0
	//test();//测试多态
	while (true) {//菜单循环显示
		//展示菜单
		wm.showMenu();
		std::cout << "请输入您的选择：";
		std::cin >> choice;
		switch (choice) {//功能选择
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.addEmp();
			break;
		case 2://显示职工
			wm.showEmp();
			break;
		case 3://删除职工
			wm.delEmp();
			break;
		case 4://修改职工
			wm.modEmp();
			break;
		case 5://查找职工
			wm.findEmp();
			break;
		case 6://排序职工
			wm.sortEmp();
			break;
		case 7://清空文件
			wm.clearFile();
			break;
		default:
			break;
		}
		system("cls");//清屏
	}
	return 0;
}

//测试多态
void test() {
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;
	Worker* worker2 = NULL;
	worker2 = new Manager(2, "李四", 1);
	worker2->showInfo();
	delete worker2;
	Worker* worker3 = NULL;
	worker3 = new Boss(3, "王五", 1);
	worker3->showInfo();
	delete worker3;
}