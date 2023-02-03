#include "workerManager.h"	//职工类
#include"worker.h"			//职工抽象基类
#include"employee.h"		//员工类
#include"manager.h"			//管理类
#include"boss.h"			//老板类
#include<iostream>//IO
#include<fstream>//用于文件交互
//using namespace std;//尽量少使用，如果使用放在所有include之后
//using std::cout;

//职工类构造函数
WorkerManager::WorkerManager() {
	std::ifstream ifs;//文件读取流对象
	ifs.open(FILENAME, std::ios::in);

	//文件不存在
	if (!ifs.is_open()) {
		//std::cout << "文件不存在" << std::endl;//测试输出
		this->empNum = 0;//初始化人数
		this->fileIsEmpty = true;//初始化文件为空标志
		this->empArray = NULL;//初始化数组指针
		ifs.close();//关闭文件
		return;
	}
	//文件存在-没有记录
	char ch;
	ifs >> ch;//读取一个字符--如果为空读取的时文件结束判断位
	if (ifs.eof()) {//到达文件尾
		//std::cout << "文件为空" << std::endl;//测试输出
		this->empNum = 0;//初始化人数
		this->fileIsEmpty = true;//初始化文件为空标志
		this->empArray = NULL;//初始化数组指针
		ifs.close();//关闭文件
		return;
	}
	//文件存在有数据
	int num = this->getNum();
	//std::cout << "职工个数为：" << num << std::endl;//测试
	this->empNum = num;//更新成员属性
	//根据职工数创建数组
	this->empArray = new Worker * [this->empNum];
	//初始化职工到数组
	initEmp();
	//测试初始化
	/*for (int i = 0; i < empNum; i++) {
		std::cout << "职工号：" << this->empArray[i]->id
			<< "\t职工姓名：" << this->empArray[i]->name
			<< "\t部门编号：" << this->empArray[i]->deptId << std::endl;
	}*/

}

//职工类析构函数
WorkerManager::~WorkerManager() {
	//释放堆空间
	if (this->empArray != NULL) {//释放堆空间职工数据
		delete[] this->empArray;
	}
}\

//清空文件
void WorkerManager::clearFile() {
	//确认提示
	int select = 0;
	do {
		std::cout << "你确认要清空？" << std::endl
			<< "1 确认" << std::endl
			<< "2 返回" << std::endl
			<< "选择：";
		std::cin >> select;
	} while (select != 1 && select != 2);
	//清空文件
	if (select == 1) {
		//文件清空
		std::ofstream ofs(FILENAME, std::ios::trunc);//如果文件存在，先删除再建立
		ofs.close();
		//清空堆区对象
		if (this->empArray != NULL) {
			//删除堆区的每个职工对象
			for (int i = 0; i < empNum; i++) {
				if (this->empArray[i] != NULL) {
					delete this->empArray[i];//释放每个堆区对象
				}
			}
			//删除堆区数组指针

			delete[] this->empArray;
			this->empArray = NULL;
			this->empNum = 0;
			this->fileIsEmpty = true;
		}
		std::cout << "清除成功！" << std::endl;
	}
	system("pause");
	system("cls");
}

//排序职工信息
void WorkerManager::sortEmp() {
	//文件不存在或者数据为空
	if (this->fileIsEmpty) {
		std::cout << "文件不存在或者信息为空" << std::endl;
	}
	else {
		std::cout<< "请选择排序方式：" << std::endl
			<< "1 按职工号升序排序" << std::endl
			<< "2 安置工号降序排列" << std::endl;
		int select = 0;
		do {
			std::cout << "选择排序：";
			std::cin >> select;
		} while (select != 1 && select != 2);
		//选择排序
		for (int i = 0; i < empNum; i++) {
			int Max = i;
			for (int j = i + 1; j < empNum; j++) {
				//升序排列
				if (select == 1) {
					if (empArray[Max]->id > empArray[j]->id) {
						Max = j;
					}
				}
				else {//降序排序
					if (empArray[Max]->id < empArray[j]->id) {
						Max = j;
					}
				}
			}
			if (i != Max) {//数据交换--每次大循环的最大/小值
				Worker* temp = empArray[i];
				empArray[i] = empArray[Max];
				empArray[Max] = temp;
			}
		}
		std::cout << "排序成功，排序后的结果为：" << std::endl;
		this->save();//保存到文件
		this->showEmp();
	}
}

//查找指定职工信息
void WorkerManager::findEmp() {
	//文件不存在或者数据为空
	if (this->fileIsEmpty) {
		std::cout << "文件不存在或者数据为空" << std::endl;
	}
	else {
		std::cout << "请选择查找方式：" << std::endl
			<< "1 按照职工编号查找" << std::endl
			<< "2 按照职工姓名查找" << std::endl;
		int select = 0;
		do {//查找选择
			std::cout << "查找方式：";
			std::cin >> select;
		} while (select != 1 && select != 2);
		if (select == 1) {// 按照职工编号查找
			int id;
			std::cout << "请输入职工编号：";
			std::cin >> id;
			int index = isExit(id);//判断数据是否存在
			if (index != -1) {
				std::cout << "查找成功，职工信息如下：" << std::endl;
				this->empArray[index]->showInfo();
			}
			else {
				std::cout << "查找失败，查无此人" << std::endl;
			}
		}
		else if (select == 2) {//按照姓名查找
			std::string name;
			std::cout << "请输入查找的姓名：";
			std::cin >> name;
			//比对信息
			bool flag = false;//查找标志
			for (int i = 0; i < empNum; i++) {
				if (this->empArray[i]->name == name) {
					std::cout << "查找成功！姓名为" << name 
						<< "的信息如下："<<std::endl;
					flag = true;
					this->empArray[i]->showInfo();
				}
			}
			if (flag == false) {//查找失败
				std::cout << "查询失败，查无此人" << std::endl;
			}
		}
		else {
			std::cout << "输入选项错误" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::modEmp() {
	if (this->fileIsEmpty) {//文件不存在或者为空
		std::cout << "文件不存在或者记录为空" << std::endl;
	}
	else {
		std::cout << "请输入修改职工的编号：";
		int id;
		std::cin >> id;

		int index = this->isExit(id);
		if (index != -1) {//职工号存在
			//获取原有数据
			int id = this->empArray[index]->id;
			std::string name = this->empArray[index]->name;
			int dId = this->empArray[index]->deptId;
			//修改数据
			//姓名
			std::cout << "原有姓名：" <<name<< "修改为姓名：";
			std::cin >> name;
			//岗位选择
			int state = 0;
			std::cout << "原有岗位："<<dId<<"请选择该职工的岗位：" << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;
			do {
				state = 0;//默认执行一次
				std::cout << "选择该职工的岗位：";
				std::cin >> dId;
				if (dId != 1 && dId != 2 && dId != 3) {//不合法重复执行
					state = 1;
				}
			} while (state);
			//信息录入
			Worker* worker = NULL;
			switch (dId) {//根据职位调用不同函数
			case 1://普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2://经理
				worker = new Manager(id, name, 2);
				break;
			case 3://老板
				worker = new Boss(id, name, 3);
				break;
			default://意外不保存
				break;
			}
			//删除原有数据
			delete this->empArray[index];
			//更新数据，数据保存
			this->empArray[index] = worker;
			//修改完成提示
			std::cout << "修改完成" << std::endl;
			//保存到文件中
			this->save();
		}
		else {
			std::cout << "修改失败，查无此人" << std::endl;
		}
	}
	//按任意按键 清屏
	system("pause");
	system("cls");
}

//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
int WorkerManager::isExit(int id) {
	int index = -1;
	for (int i = 0; i < this->empNum; i++) {
		if (this->empArray[i]->id == id) {//职工号存在
			index = i;
			break;
		}
	}
	return index;
}

//删除职工
void WorkerManager::delEmp() {
	//1 文件不存在或者无数据
	if (this->fileIsEmpty) {
		std::cout << "文件不存在或者记录为空" << std::endl;
	}
	else {
		//按照职工编号删除
		std::cout << "请输入想要删除的职工号：";
		int id = 0;
		std::cin >> id;
		int index = this->isExit(id);
		if (index != -1) {//数据存在
			for (int i = index; i < this->empNum; i++) {//从待删除数据往后数据前移
				this->empArray[i] = this->empArray[i + 1];
			}
			this->empNum--;
			this->save();//删除后数据同步到文件
			std::cout << "删除成功" << std::endl;
		}
		else {//数据不存在
			std::cout << "删除失败，未找到该职工" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

//显示职工
void WorkerManager::showEmp() {
	//判断数据存不存在
	if (this->fileIsEmpty) {
		std::cout << "文件不存在或者为空" << std::endl;
	}
	else {
		for (int i = 0; i < empNum; i++) {
			//利用多态调用接口
			this->empArray[i]->showInfo();
		}
	}
	//暂停屏幕
	system("pause");
	system("cls");
}

//初始化文件中的员工
void WorkerManager::initEmp() {//从文件中读取对象数据并存储到数组中
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);//读取文件
	int id;
	std::string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		//根据不同职位创建不同的对象
		if (dId == 1) {//1 普通员工
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {//2 经理
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) {//3 老板
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->empArray[index] = worker;
		index++;
	}
}

//统计文件中的人数
int WorkerManager::getNum() {//通过读取文件获取文件数目
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);//读取
	//中间变量
	int id;
	std::string name;
	int dId;

	int num = 0;//统计数据
	while (ifs >> id && ifs >> name && ifs >> dId) {//每次从文件中读取三个数据（一组为一个人的）
		//记录人数
		num++;
	}
	ifs.close();//关闭文件
	return num;//返回数据
}
//保存文件
void WorkerManager::save() {
	std::ofstream ofs;//创建对象流
	ofs.open(FILENAME, std::ios::out);//为写文件而打开文件
	for (int i = 0; i < this->empNum; i++) {//数据存储
		ofs << this->empArray[i]->id << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->deptId << std::endl;
	}
	//关闭文件
	ofs.close();
}

//增加职工
void WorkerManager::addEmp() {
	std::cout << "请输入增加职工数量：";
	int addNum = 0;
	std::cin >> addNum;
	if (addNum > 0) {//输入数据合法
		//计算新空间大小
		int newSize = this->empNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];//注意使用完要销毁
		//将原有空间下内容转移到新空间中
		if (this->empArray != NULL) {//原有数据存在
			for (int i = 0; i < this->empNum; i++) {
				if (i < newSize) {//如果没有判断报错C6386 虽然似乎报错没有什么意义
					newSpace[i] = this->empArray[i];
				}
			}
		}
		//输入新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			std::string name;
			int dId;
			//信息输入
			std::cout << "***********************************" << std::endl;
			//编号
			std::cout << "请输入第" << i + 1 << "个职工编号：";
			std::cin >> id;
			//姓名
			std::cout << "请输入第" << i + 1 << "个职工姓名：";
			std::cin >> name;
			//岗位选择
			int state = 0;
			std::cout << "请选择该职工的岗位：" << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;
			do {
				state = 0;//默认执行一次
				std::cout << "选择该职工的岗位：";
				std::cin >> dId;
				if (dId != 1 && dId != 2 && dId != 3) {//不合法重复执行
					state = 1;
				}
			} while (state);
			//信息录入
			Worker* worker = NULL;
			switch (dId) {//根据职位调用不同函数
			case 1://普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2://经理
				worker = new Manager(id, name, 2);
				break;
			case 3://老板
				worker = new Boss(id, name, 3);
				break;
			default://意外不保存
				break;
			}
			//存入新空间
			int t = this->empNum + i;
			if (t < newSize) {//不判断同上警报报错
				newSpace[t] = worker;
			}
		}
		//释放原有空间
		delete[] this->empArray;	//释放数组空间
		//更改新空间指向
		this->empArray = newSpace;
		//更新个数
		this->empNum = newSize;
		//更新职工不为空标志
		this->fileIsEmpty = false;
		//保存文件
		this->save();
		//提示信息
		std::cout << "\n成功添加" << addNum << " 名新职工！" << std::endl;
	}
	else {//输入数据不合法
		std::cout << "输入数据不合法" << std::endl;
	}
	system("pause");
	system("cls");
}

//显示菜单
void WorkerManager::showMenu() {
	std::cout << "********************************************" << std::endl;
	std::cout << "*********  欢迎使用职工管理系统！ **********" << std::endl;
	std::cout << "*************  0.退出管理程序  *************" << std::endl;
	std::cout << "*************  1.增加职工信息  *************" << std::endl;
	std::cout << "*************  2.显示职工信息  *************" << std::endl;
	std::cout << "*************  3.删除离职职工  *************" << std::endl;
	std::cout << "*************  4.修改职工信息  *************" << std::endl;
	std::cout << "*************  5.查找职工信息  *************" << std::endl;
	std::cout << "*************  6.按照编号排序  *************" << std::endl;
	std::cout << "*************  7.清空所有文档  *************" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;
}

//退出程序
void WorkerManager::exitSystem() {
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);// 清理I/O缓冲区后再退出进程
}