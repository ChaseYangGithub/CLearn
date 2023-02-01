#include<iostream>
using namespace std;

//构造函数的分类及调用
/*
构造函数的分类：
	按参数分为：有参构造和无参构造
	按类型分为：普通构造和拷贝构造
三种调用方式：
	括号法
	显示法
	隐式转换法
*/

//人类
class Human {
public:
	int age;
public:
	//无参(默认）构造函数
	Human() {
		cout << "无参构造函数" << endl;
	}
	//有参构造函数
	Human(int a) {
		cout << "有参构造函数" << endl;
	}
	//拷贝构造函数
	Human(const Human& p) {
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}
	//析构函数
	~Human() {
		cout << "析构函数" << endl;
	}
};

//2.构造函数的调用

//调用无参构造函数
void test1() {
	Human h;//调用无参构造函数
}
//调用有参构造函数
void test2() {
	//1括号法常用
	Human h1(20);
	//调用无参构造函数不能加括号，如果加括号编译器会认为是函数声明
	//Human h2();

	//显示法
	Human h2 = Human(10);
	Human h3 = Human(h2);//拷贝构造
	//Human(10)单独写是匿名对象 当行为结束后马上析构

	//隐式转换法
	Human h4 = 10;	//等价于 Human h4 =Human(10)
	Human h5 = h4;	//拷贝构造

	//不能使用拷贝构造函数来初始化匿名对象，编译器会认为是对象声明 Human (h5)==Human h5
	//Human(h5);
}


//构造函数的分类及调用
void constructionClassification() {
	test1();//调用无参函数
	test2();//调用有参函数
}
