#ifndef MAINFUNC
#define MAINFUNC
#include<iostream>
#include"human.h"
//主程序菜单
void main_Menu();
//登陆函数
void loginIn(std::string fileName, int type);
//管理员菜单
void managerMenu(Human*& manager);//&说明manager是一个引用*确定其引用的是指针

//学生子菜单
void studentMenu(Human*& student);

//教师登陆菜单
void teacherMenu(Human*& teacher);
#endif // MAINFUNC
