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
