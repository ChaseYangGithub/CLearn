* 文件基本上是基于黑马程序视频 ，主体文档参考，部分添加自己需要的内容，仅用于自己学习！
* 链接：[黑马程序视频课程](https://www.bilibili.com/video/BV1et411b73Z?p=282&vd_source=54d6f5e269c668b7d2e2c71481a13789)
* `GitHub`:[链接](https://github.com/ChaseYangGithub/CLearn)

# 机房预约系统

## 1、机房预约系统需求

### 1.1 系统简介

* 学校现有几个规格不同的机房，由于使用时经常出现"撞车"现象,现开发一套机房预约系统，解决这一问题。

### 1.2 身份简介

分别有三种身份使用该程序

* **学生代表**：申请使用机房
* **教师**：审核学生的预约申请
* **管理员**：给学生、教师创建账号

### 1.3 机房简介

机房总共有3间

* 1号机房   --- 最大容量30人
* 2号机房   --- 最多容量50人
* 3号机房   --- 最多容量100人

### 1.4 申请简介

* 申请的订单每周由管理员负责清空。
* 学生可以预约未来一周内的机房使用，预约的日期为周一至周五，预约时需要选择预约时段（上午、下午）
* 教师来审核预约，依据实际情况审核预约通过或者不通过

### 1.5 系统具体需求

* 首先进入登录界面，可选登录身份有：
  * 学生代表
  * 老师
  * 管理员
  * 退出
* 每个身份都需要进行验证后，进入子菜单
  * 学生需要输入 ：学号、姓名、登录密码
  * 老师需要输入：职工号、姓名、登录密码
  * 管理员需要输入：管理员姓名、登录密码
* 学生具体功能
  * 申请预约    ---   预约机房
  * 查看自身的预约    ---  查看自己的预约状态
  * 查看所有预约   ---   查看全部预约信息以及预约状态
  * 取消预约    ---   取消自身的预约，预约成功或审核中的预约均可取消
  * 注销登录    ---   退出登录
* 教师具体功能
  * 查看所有预约   ---   查看全部预约信息以及预约状态
  * 审核预约    ---   对学生的预约进行审核
  * 注销登录    ---   退出登录
* 管理员具体功能
  * 添加账号    ---   添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
  * 查看账号    ---   可以选择查看学生或教师的全部信息
  * 查看机房    ---   查看所有机房的信息
  * 清空预约    ---   清空所有预约记录
  * 注销登录    ---   退出登录

## 2 主菜单

### 2.1菜单实现

* 实现显示菜单登录选项

在`00 机房预约系统.cpp`中实现`main_Menu()`，对应声明放在对应头文件中

`00 机房预约系统.cpp`

```C++
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

```

`main_Menu()`

```C++
#ifndef MAINFUNC
#define MAINFUNC
//主程序菜单
void main_Menu();

#endif // MAINFUNC
```

### 2.2菜单选择

`00 机房预约系统.cpp`

```C++
#include<iostream>
#include "00 机房预约系统.h"


int main() {
	int select = -1;//默认重新选择程序
	while (true) {
		main_Menu();//弹出登陆菜单选项
		std::cin >> select;
		switch (select) {
		case 1://学生登陆
			break;
		case 2://教师登录
			break;
		case 3://管理员登陆
			break;
		case 0://退出程序
			std::cout << "退出程序测试！" << std::endl;
			break;
		default://默认循环
			std::cout << "请重新输入选项！" << std::endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}
```

## 3 退出程序

* main函数修改程序

```C++
		case 0://退出程序
			system("cls");
			std::cout << "欢迎下次使用！" << std::endl;
			system("pause");
			return 0;
			break;
```

## 4 创建身份

### 4.1身份基类

三种身份有共性也有特性，则创建基类human

`human.h`

```C++
#ifndef HUMAN
#define HUMAN
#include<iostream>
//基类Human
class Human {
public:
	//操作菜单
	virtual void operMenu();//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用--C++核心 多态
public:
	std::string username;//用户名
	std::string password;//密码
};
#endif // HUMAN

```

`human.cpp`

```C++
#include<iostream>
#include "human.h"

void Human::operMenu() {

}
```



### 4.2学生类

* 学生类主要功能是可以通过类中成员函数，实现预约实验室操作

* 学生类中主要功能有：

  * 显示学生操作的菜单界面
  * 申请预约
  * 查看自身预约
  * 查看所有预约
  * 取消预约


`student.h`

```C++
#ifndef STUDENT
#define STUDENT
#include<iostream>
#include "human.h"//继承基类需要
//学生类
class Student :public Human {
public:
	//默认构造
	Student();
	//有参构造（学号 姓名 密码）
	Student(int id, std::string username, std::string password);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看我的预约
	void showMyApply();
	//查看所有预约
	void showAllApply();
	//取消预约
	void cancleApply();
public:
	int id;//学生学号
	
};

#endif
```

`student.cpp`

```C++
#include<iostream>
#include "student.h"

//默认构造函数
Student::Student() {
	id = -1;//防止未初始化警告

}
//带参构造函数
Student::Student(int id, std::string name, std::string password) {
	this->id = id;
	this->username = name;
	this->password = password;
}
//菜单界面
void Student::operMenu() {

}
//申请预约
void Student::applyOrder() {

}
//查看个人预约
void Student::showMyApply() {

}
//查看所有预约
void Student::showAllApply() {

}
//取消预约
void Student::cancleApply() {

}
```

### 4.3 教师类

- 教师类主要功能是查看学生的预约，并进行审核

- 教师类中主要功能有：

  - 显示教师操作的菜单界面

  - 查看所有预约

  - 审核预约

`teacher.h`

```c++
#ifndef TEACHER 
#define TEACHER
#include "human.h"
#include<iostream>
//教师类
class Teacher :public Human {
public:
	//默认构造函数
	Teacher();
	//有参构造函数
	Teacher(int id, std::string name, std::string password);
	//显示教师操作菜单
	virtual void operMenu();
	//显示所有预约
	void showAllApply();
	//审核预约
	void reviewApply();
public:
	int id;//教师编号
};
#endif
```

`teacher.cpp`

```C++
#include<iostream>
#include "teacher.h"
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

}
//显示所有预约
void Teacher::showAllApply() {

}
//审核预约
void Teacher::reviewApply() {

}
```

### 4.4管理员类

- 管理员类主要功能是对学生和老师账户进行管理，查看机房信息以及清空预约记录

- 管理员类中主要功能有：

  - 显示管理员操作的菜单界面

  - 添加账号

  - 查看账号

  - 查看机房信息

  - 清空预约记录

`manager.h`

```C++
#ifndef	MANAGER
#define MANAGER
#include<iostream>
#include "human.h"
//管理员类
class Manager :public Human {
public:
	//默认构造函数
	Manager();
	//有参构造函数
	Manager(std::string username, std::string password);
	//显示管理员操作菜单
	void operMenu();
	//添加账号
	void addAccount();
	//查看账号
	void showAccount();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void clearRecord();
};
#endif
```

`manager.cpp`

```
#include<iostream>
#include "manager.h"

//默认构造函数
Manager::Manager() {

}
//有参构造函数
Manager::Manager(std::string username, std::string password) {
	this->username = username;
	this->password = password;
}
//显示管理员操作菜单
void Manager::operMenu() {

}
//添加账号
void Manager::addAccount() {

}
//查看账号
void Manager::showAccount() {

}
//查看机房信息
void Manager::showComputer() {

}
//清空预约记录
void Manager::clearRecord() {

}
```

## 5 登陆模块

### 5.1 全局文件名设置

由于有很多文件设置一个全局文件包含所有文件名便于查看和修改

`globalFile.h`

```C++
#ifndef GLOBALFILE
#define GLOBALFILE
//管理员文件
#define ADMIN_FILE manager.txt"
//学生文件
#define	STUDENT_FILE "student.txt"
//教师文件
#define TEACHER_FILE "teacher.txt"
//机房文件
#define COMPUTER_FILE "computer.txt"
//预约文件
#define ORDER_FILE "order.txt"
#endif
```

### 5.2登陆函数封装

将整个登陆放在一个文件中，不同登陆调用文件不同

在主程序中创建函数`loginIn()`

创建完成后在主程序中填写不同调用函数

`loginIn()`

```C++
//登陆函数 按照文件名和登陆类型打开文件执行登陆操作
void loginIn(std::string fileName, int type) {
	Human* person = NULL;
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

	int id;
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
	}
	else if (type == 2) {
		//教师登陆验证
	}
	else if(type==3){
		//管理员登陆验证
	}
	std::cout << "登陆验证失败，请检查账户或者密码！" << std::endl;
	system("pause");
	system("cls");
	return;

}
```

```C++
case 1://学生登陆
			loginIn(STUDENT_FILE, 1);
			break;
		case 2://教师登录
			loginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员登陆
			loginIn(ADMIN_FILE, 3);
			break;
```

### 5.3学生登陆实现

依次从文件中读取数据校验数据如果校验成功创建对象 否则 退出

在`loginIn`case1中添加代码（下同）

完成后创建文件并测试

可直接使用ctrl+N创建文本文件

```C++
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
				person = new Student(id, username, pwd);

				return;
			}
```

### 5.4教师登陆实现

```C++
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
				person = new Teacher(id, username, pwd);

				return;
			}
		}
```

5.5管理员登陆实现

```C++
//管理员登陆验证
		std::string duser;
		std::string dpwd;
		while (ifs >> duser && ifs >> dpwd) {//一次读取三个数据且不为空
			if (duser == username && dpwd == pwd) {
				//校验成功
				std::cout << "管理员" << username << "登陆系统" << std::endl;
				system("pause");
				system("cls");
				person = new Manager(username, pwd);

				return;
			}
		}
```

## 6管理员模块

### 6.1管理员登录和注销

#### 6.1.1管理员子菜单

* 在机房预约系统.cpp中，当用户登录的是管理员，添加管理员菜单接口
* 将不同的分支提供出来
  * 添加账号
  * 查看账号
  * 查看机房
  * 清空预约
  * 注销登录
* 实现注销功能

`managerMenu()`

```C++
//管理员子菜单
void managerMenu(Human*& manager) {
	int select = -1;//默认循环
	while (true) {
		//管理员菜单
		manager->operMenu();
		Manager* man = (Manager*)manager;//强转防止调用父类的函数
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

```

#### 6.1.2菜单功能实现

`orderMenu`

```C++
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
```

然后在管理员登陆分支中添加代码进入管理员子菜单

### 6.2添加账号

功能描述：

* 给学生或教师添加新的账号

功能要求：

* 添加时学生学号不能重复、教师职工号不能重复

#### 6.2.1功能简单实现

* 确认添加账号类型
* 添加信息
* 录入文件

```C++
//添加账号
void Manager::addAccount() {
	std::string fileName;//文件类型
	std::string name;
	std::string password;
	std::string pwd;//校验
	int id=-1;
	int select;//选择
	//类型选择
	while (true) {
		std::cout << "1 添加老师账号" << std::endl;
		std::cout << "2 添加学生账号" << std::endl;
		std::cout << "请输入添加账号类型：";
		std::cin >> select;
		if (select == 1) {
			fileName = TEACHER_FILE;
			std::cout << "请输入职工编号：";
			break;
		}
		else if (select == 2) {
			fileName = STUDENT_FILE;
			std::cout << "请输入学生学号：";
			break;
		}
	}
	std::cin >>id;
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
	system("pause");
	system("cls");

}
```

#### 6.2.2去重

* 从文件中获取数据到容器

* 在管理员中添加学生容器和教师容器 `manager.h`

  ```C++
  #include<vector>	//容器
  #include "student.h"
  #include "teacher.h"
  
  	//初始化容器
  	void initVector();
  public:
  	std::vector<Student> sV;
  	std::vector<Teacher> tV;
  ```

  

* 添加容器初始化函数

* 在管理员构造函数中初始化

```C++
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
	std::cout << "当前教师数据为：" << tV.size() << std::endl;
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
	std::cout << "当前学生数据为：" << sV.size() << std::endl;
	//关闭文件
	ifs.close();

}
```

```C++
//有参构造函数
Manager::Manager(std::string username, std::string password) {
	this->username = username;
	this->password = password;
	//初始化容器
	this->initVector();
}
```

* 添加去重函数
* 仅检测编号`bool Manager::checkRepeat(int id, int type) `

```C++
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
```

* 添加去重函数到添加账号实现`void Manager::addAccount()`
* 仅显示修改部分

```C++
	bool repeat = true;//重复校验
	std::string errorType;//报错信息
	
	
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
		//编号重复
	while (repeat) {
		std::cin >> id;
		repeat = checkRepeat(id, select);
		if (repeat) {
			std::cout << errorType << std::endl;
		}
	}
		
	
```

* 在添加账号之后重初始化容器



### 6.3显示账号

* 打印数据 `manager.cpp`

```C++
//通用打印
template<class T>
void printInfo(T& s) {
	std::cout << s.id <<"\t" << s.username<<"\t" << s.password << std::endl;
}
```



* 显示账号

  ```C++
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
  ```

  

### 6.4查看机房

#### 6.4.1创建机房类

* 属性 房间号 台数 

```C++
#ifndef COMPUTER
#define COMPUTER
#include<iostream>
//机房类
class Computer {
public:
	int room;//机房号
	int capacity;//机房最大容量
	int size;//当前使用量
};
#endif

```

#### 6.4.2初始化机房信息

* 在Manager下新建机房容器
* 在Manager下新建函数初始化机房

```C++
//初始化机房信息
void Manager::initComputer() {
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	Computer c;
	while (ifs >> c.room && ifs >> c.size) {
		cV.push_back(c);
	}
	std::cout << "当前机房数量：" << cV.size() << std::endl;
	ifs.close();
}
```

#### 6.4.3机房信息显示

```C++
//初始化机房信息
void Manager::initComputer() {
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	Computer c;
	while (ifs >> c.room && ifs >> c.capacity&&ifs>>c.size) {
		cV.push_back(c);
	}
	std::cout << "当前机房数量：" << cV.size() << std::endl;
	ifs.close();
}
```

### 6.5清空记录

```C++
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
```

## 7 学生模块

### 7.1学生登录和注销

#### 7.1.1学生子菜单

- 在`机房预约系统.cpp`中，当用户登录的是学生，添加学生菜单接口
- 将不同的分支提供出来
  - 申请预约
  - 查看我的预约
  - 查看所有预约
  - 取消预约
  - 注销登录
- 实现注销功能

添加全局函数 `void studentMenu(Human * &student)` 代码如下：

```C++
//学生子菜单
void studentMenu(Human*& student) {
	int select = -1;//默认循环
	while (true) {
		//学生菜单
		student->operMenu();
		Student* man = (Student*)student;//强转防止调用父类的函数
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
```

#### 7.1.2菜单显示

```C++
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
```

### 7.2申请预约

#### 7.2.1信息获取

* 添加成员机房容器

```C++
	std::vector<Computer> sC;//机房
```

* 初始化机房容器函数  并放进有参构造函数

```C++
//初始化机房信息
void Student::initComputer() {
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	Computer c;
	while (ifs >> c.room && ifs >> c.capacity&&ifs>>c.size) {
		sC.push_back(c);
	}
	ifs.close();
}
```

#### 7.2.2预约实现

* 申请日期 
* 上下午
* 机房号
* 机房满

```C++
//机房满
bool Student::roomFull(int room) {
	for (std::vector<Computer>::iterator it = sC.begin(); it != sC.end(); it++) {
		if (it->room == room && it->capacity > it->size) {
			return false;
		}
	}
	return true;
}
```

* 机房申请

```C++
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

	system("pause");
	system("cls");
}
```

### 7.3查看预约

#### 7.3.1创建类

* 头文件`order.h`

  ```C++
  #ifndef ORDER
  #define ORDER
  #include<iostream>
  #include<map>
  //预约类
  class Order {
  public:
  	//构造函数
  	Order();
  	//更新预约记录
  	void UpdateOrder();
  public:
  	//记录的容器  记录的条数  具体的信息
  	std::map<int ,std::map<std::string, std::string>> data;
  	//预约记录的条数
  	int size;
  };
  #endif
  ```

  

* 构造函数

  ```C++
  //构造函数
  Order::Order() {
  	std::string data;//日期
  	std::string time;//上下午
  	std::string id;//学号
  	std::string username;//姓名
  	std::string room;//机房
  	std::string status;//状态
  	std::ifstream ifs;
  	std::string key;//键值 用于存储数据到容器
  	std::string value;//值 用于存储数据到容器
  	std::map<std::string, std::string> m;
  	int pos = -1;//用于记录：位置
  	this->size = 0;//记录数
  	ifs.open(ORDER_FILE, std::ios::in);
  	while (ifs >> data && ifs >> time && ifs >> id && ifs >> username && ifs >> room && ifs >> status) {
  		//测试代码--测试读取
  	/*	std::cout << data << std::endl;
  		std::cout << time << std::endl;
  		std::cout << id << std::endl;
  		std::cout <<username << std::endl;
  		std::cout << room << std::endl;
  		std::cout << status << std::endl;*/
  		m.clear();
  		//std::map<std::string, std::string> m;
  		//map自带的.clear()函数会清空map里存储的所有内容，但如果map值存储的是指针，则里面的值不会被清空
  		
  		//日期 中文及中文字符占据两个单位
  		//pos = (int)data.find("日");//0
  		//pos = (int)data.find("期");//2
  		pos = (int)data.find("：");//4--find找的是当前字符开始位置，若想从下一个数据开始要+2（当前中文）
  		//如果使用英文:则+1
  		//std::cout << pos;
  		if (pos != -1) {
  			//返回pos开始  长度为n的string
  			key = data.substr(0, pos + 2);//备注值 从 下标0开始长度为pos+2个数据
  			value = data.substr(pos + 2, data.size() - pos - 1);
  		/*	std::cout << key;
  			std::cout << value<<std::endl;*/
  			m.insert(std::make_pair(key, value));
  		}
  		//上下午
  		pos = (int)time.find("：");//查找冒号锁定数据
  		if (pos != -1) {
  			//返回pos开始  长度为n的string
  			key = time.substr(0, pos + 2);//备注值
  			value = time.substr(pos + 2, time.size() - pos - 1);
  			/*	std::cout << key;
  			std::cout << value<<std::endl;*/
  			m.insert(std::make_pair(key, value));
  		}
  		//学号
  		pos = (int)id.find("：");//查找冒号锁定数据
  		if (pos != -1) {
  			//返回pos开始  长度为n的string
  			key = id.substr(0, pos + 2);//备注值
  			value = id.substr(pos + 2, id.size() - pos - 1);
  			/*	std::cout << key;
  			std::cout << value<<std::endl;*/
  			m.insert(std::make_pair(key, value));
  		}
  		//姓名
  		pos = (int)username.find("：");//查找冒号锁定数据
  		if (pos != -1) {
  			//返回pos开始  长度为n的string
  			key = username.substr(0, pos + 2);//备注值
  			value = username.substr(pos + 2, username.size() - pos - 1);
  			/*	std::cout << key;
  			std::cout << value<<std::endl;*/
  			m.insert(std::make_pair(key, value));
  		}
  		//机房
  		pos = (int)room.find("：");//查找冒号锁定数据
  		if (pos != -1) {
  			//返回pos开始  长度为n的string
  			key = room.substr(0, pos + 2);//备注值
  			value = room.substr(pos + 2, room.size() - pos - 1);
  			/*	std::cout << key;
  			std::cout << value<<std::endl;*/
  			m.insert(std::make_pair(key, value));
  		}
  		//状态
  		pos = (int)status.find("：");//查找冒号锁定数据
  		if (pos != -1) {
  			//返回pos开始  长度为n的string
  			key = status.substr(0, pos + 2);//备注值
  			value = status.substr(pos + 2, status.size() - pos - 1);
  			/*	std::cout << key;
  			std::cout << value<<std::endl;*/
  			m.insert(std::make_pair(key, value));
  		}
  		//保存数据到容器
  		this->data.insert(std::make_pair(this->size, m));
  		this->size++;//预约数量加1
  	}
  	//更新预约记录测试
  	//std::string test = this->data[0]["日期："];//2
  	//std::cout << test;
  	
  	//代码测试--测试文件输出
  	//for (std::map<int, std::map<std::string, std::string>>::iterator it = this->data.begin(); it != this->data.end(); it++) {
  	//	std::cout << "key:" << it->first << " value:\t";
  	//	for (std::map<std::string, std::string>::iterator t = it->second.begin(); t != it->second.end(); t++) {//输出单行内容
  	//		std::cout << t->first << " " << t->second << " ";
  	//	}
  	//	std::cout << std::endl;
  	//}
  	ifs.close();
  }
  ```

* map容器
* 在没有清空时内容一致

![image-20230226153015257](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302271653294.png)

* 清空之后内容正常

![image-20230226153142666](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302271653295.png)

* 清空与内部循环定义结果一致

![image-20230226153413982](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302271653296.png)

* map自带的.clear()函数会清空map里存储的所有内容，但如果map值存储的是指针，则里面的值不会被清空
* 构造函数中参数均为string类型为char指针

* 更新预约记录`updateOrder()`  

```C++
//更新预约记录
void Order::UpdateOrder() {
	if (this->size == 0) {
		return;//说明没有要更新的数据
	}

	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);//如果存在先删除在创建
	for (int i = 0; i < this->size; i++) {
		ofs << "日期：" << this->data[i]["日期："] << " "; // find element matching _Keyval or insert value-initialized value
		ofs << "代码：" << this->data[i]["代码："] << " ";
		ofs << "学号：" << this->data[i]["学号："] << " ";
		ofs << "姓名：" << this->data[i]["姓名："] << " ";
		ofs << "机房：" << this->data[i]["机房："] << " ";
		ofs << "状态：" << this->data[i]["状态："] << std::endl;
	}
	ofs.close();
}
```

只有当 map 容器中确实存有包含该指定键的键值对，借助重载的 [ ] 运算符才能成功获取该键对应的值；反之，若当前 map 容器中没有包含该指定键的键值对，则此时使用 [ ] 运算符将不再是访问容器中的元素，而变成了向该 map 容器中增添一个键值对。

#### 7.3.2显示自身预约

*  对象数据为空返回
* 不为空读取判断数据

```C++
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
			std::cout<< i + 1;
			std::string mes ="、预约日期：周";
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
```

#### 7.3.3查看所有预约

```C++
//查看所有预约
void Student::showAllApply() {
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
		std::cout<< i + 1;
		std::string mes ="、预约日期：周";
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
```

### 7.4取消预约

* 读取显示个人预约
* 修改指定个人预约数据状态

```C++
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
```

## 8 教职工模块

### 8.1登陆和注销

#### 8.1.1教职工子菜单

- 在机房预约系统.cpp中，当用户登录的是教师，添加教师菜单接口
- 将不同的分支提供出来
  - 查看所有预约
  - 审核预约
  - 注销登录
- 实现注销功能

添加全局函数 `void TeacherMenu(Person * &manager)` 

```C++
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
```

#### 8.1.2菜单显示

```C++
//教师操作菜单
void Teacher::operMenu() {
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "\t\t|\t1 查看所有预约\t|" << std::endl;
	std::cout << "\t\t|\t2 审核预约\t|" << std::endl;
	std::cout << "\t\t|\t0 注销登录\t|" << std::endl;
	std::cout << "\t\t-------------------------" << std::endl;
	std::cout << "请输入功能选项：";
}
```

### 8.2查看所有预约

* 同上

```C++
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
			mes+= "预约失败";
			break;
		}
		std::cout << mes << std::endl;
	}
	system("pause");
	system("cls");
}
```

### 8.3审核预约

* 筛选所有可以审核的预约
* 选择审核

* 更新数据
* 基本与学生取消预约相同

```C++
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
```

