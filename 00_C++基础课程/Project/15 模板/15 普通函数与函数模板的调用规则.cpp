#include<iostream>
//普通函数与函数模板的调用规则

void myprint(int a, int b) {
	std::cout << "调用的普通函数" << std::endl;
}

template<class T>
void myPrint(T a, T b) {
	std::cout << "调用模板函数" << std::endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	std::cout << "调用重载的模板函数"<<std::endl;
}
// 既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性

//普通函数与模板函数的调用规则
void test15() {
	//1 如果函数模板和普通函数都可以实现，优先调用普通函数
	// 注意 如果告诉编译器  普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
	int a = 10;
	int b = 20;
	int c = 30;

	myPrint(a, b);//调用普通函数

	//2 可以通过空模板参数列表来强调使用函数模板
	myPrint<>(a, b);//调用函数模板

	//3 函数模板也可以发生重载
	myPrint(a, b, c);//调用函数的重载模板

	//4 如果函数模板可以产生更好的匹配，优先调用函数模板
	char d1 = 'c';
	char d2 = 'd';
	myPrint(d1, d2);//调用函数模板
}