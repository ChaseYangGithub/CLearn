#include<iostream>
//函数模板语法
// 函数模板作用：
//建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。
//制作模板-通用交换函数

//交换整型函数
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//交换浮点型函数
void swapFloat(float& a, float& b) {
	float temp = a;
	a = b;
	b = temp;
}
/*
template  ---  声明创建模板
typename  --- 表示其后面的符号是一种数据类型，可以用class代替
T    ---   通用的数据类型，名称可以替换，通常为大写字母

* 函数模板利用关键字 template
* 使用函数模板有两种方式：自动类型推导、显示指定类型
* 模板的目的是为了提高复用性，将类型参数化
*/
//利用模板提供通用的交换函数
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//模板基础测试
void templateTest01() {
	int a = 5;
	int b = 10;
	//swapInt(a, b);

	//利用模板实现
	//1 自动导入实现
	//mySwap(a, b);

	//2 显式指定类型
	mySwap<int>(a, b);

	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
}