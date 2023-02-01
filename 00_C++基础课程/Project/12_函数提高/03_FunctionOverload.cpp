#include<iostream>
using namespace std;
#include "00_函数.h"
/*
作用：函数名可以相同，提高复用性

函数重载满足以下条件：
	同一个作用域
	函数名称相同
	函数参数不同或者个数不同或者顺序不同

！！函数的返回值不可作为函数重载的条件
*/

void Func() {
	cout << "Func的调用" << endl;
}
void Func(int a) {
	cout << "Func(int a)的调用" << endl;
}
void Func(int a, int b,int c) {
	cout << "Func(int a,int b,int c)的调用" << endl;
}
void Func(double a) {
	cout << "Func(double a)的调用" << endl;
}

//函数返回值不可以作为函数重载条件
//int Func() {
//	cout << "int Func的调用" << endl;
//	return 1;
//}

//函数重载
void FunctionOverload() {
	Func();
	Func(1);
	Func(1, 2,3);
	Func(2.0);
}

//1、引用作为重载条件
void Case1(int& a) {
	cout << "Case1(int &a)的调用" << endl;
}
//1、引用作为重载条件
void Case1(const int& a) {
	cout << "Case1(const int &a)的调用" << endl;
}
//函数重载碰到函数默认参数
void Case2(int a) {
	cout << "Case2(int a)函数调用" << endl;
}
//函数重载碰到函数默认参数
void Case2(int a, int b = 10) {
	cout << "Case2(int a,int b=10)的调用" << endl;
}


//函数重载注意事项
void Notice() {
	int a = 10;
	Case1(a);//调用无const
	Case1(10);//调用有const 此时走const是因为 int &a=10不合法，而const int &a合法（详细见函数const部分）
	//Case2(a);//碰到默认参数产生歧义
}