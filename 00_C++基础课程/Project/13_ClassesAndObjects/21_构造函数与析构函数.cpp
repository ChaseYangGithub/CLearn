#include<iostream>
using namespace std;
//构造函数与析构函数
/*
构造函数语法：类名(){}
1. 构造函数，没有返回值也不写void
2. 函数名称与类名相同
3. 构造函数可以有参数，因此可以发生重载
4. 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次

析构函数语法：~类名(){}
1. 析构函数，没有返回值也不写void
2. 函数名称与类名相同,在名称前加上符号  ~
3. 析构函数不可以有参数，因此不可以发生重载
4. 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
*/

//Persons对象
class Persons {
public:
	//构造函数
	Persons() {
		cout << "Persons的构造函数！" << endl;
	}
	//析构函数
	~Persons() {
		cout << "Persons的析构函数！" << endl;
	}
};
//测试运行
void constructionAndDestruction() {
	Persons p1;
}