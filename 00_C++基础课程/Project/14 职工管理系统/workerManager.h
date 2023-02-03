#ifndef WorkerManager_H	//防止头文件的重复包含和编译 一般名字设置为文件名大写加上H,C++ 5th推荐加下划线6th没有
#define WorkerManager_H
#include "worker.h"
#include<fstream>	//用于文件交互
#define FILENAME "empFile.txt"//存储文件名常量
//职工类
class WorkerManager {
public:
	//构造函数
	WorkerManager();
	//析构函数
	~WorkerManager();
	//清空文件
	void clearFile();
	//排序信息
	void sortEmp();
	//查找职工信息
	void findEmp();
	//修改职工信息
	void modEmp();
	//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
	int isExit(int id);
	//删除职工
	void delEmp();
	//显示职工
	void showEmp();
	//初始化文件中员工
	void initEmp();
	//统计文件中的人数
	int getNum();
	//保存文件
	void save();
	//展示菜单
	void showMenu();
	//退出程序
	void exitSystem();
	//增加职工
	void addEmp();
public:
	//记录文件中的人数个数
	int empNum;
	//员工数组的指针
	Worker** empArray;//定义指向数据格式为指针的指针
	//文件是否为空
	bool fileIsEmpty;
};
#endif
//VS默认#pragma once但是使用了支持更加广泛的ifndef