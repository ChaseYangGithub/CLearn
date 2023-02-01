#include<iostream>
using namespace std;
/*
封装是面向对象三大特性之一
封装的意义在于：
	将属性和行为作为一个整体，表现生活中的事务
	将属性和行为加以权限控制
		权限有三种：
		public 公开
		protected 保护权限
		private	私有权限
*/



//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student {
//公共函数
public:
	//设置姓名
	void setName(string name) {
		uname = name;
	}
	//设置id
	void setId(int id) {
		uid = id;
	}
	//显示学生信息
	void showStudent() {
		cout << "name:" << uname << "ID:" << uid << endl;
	}
//属性
public:
	string uname;//学生姓名
	int uid;//学生id
};

//圆周率
const double PI = 3.14;
//封装圆类，求圆的周长
class Circle {
public://访问权限 公共
	//属性
	int r;//半径

	//行为
	//获取圆的周长
	double calculateCircle() {
		//获取圆的周长
		return 2 * PI * r;
	}
};

//封装案例
void encapsulation() {
	//1.在设计类的时候将属性和行为写在一起，表现事务
		//求圆周
	cout << "案例1：求圆周" << endl;
	Circle c;//通过圆类创建圆的对象
	c.r = 10;
	cout << "圆的周长为：" << c.calculateCircle() << endl;
	//显示学生信息
	cout << "案例2：显示学生信息" << endl;
	Student s;
	s.setName("张三");
	s.setId(123);
	s.showStudent();
}
