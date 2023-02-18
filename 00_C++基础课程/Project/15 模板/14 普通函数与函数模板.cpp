#include<iostream>

//普通函数
int myAdd01(int a, int b) {
	return a + b;
}

//函数模板
template<class T>
T myAdd02(T a, T b) {
	return a + b;
}

//函数与模板函数
void test14() {
	//使用函数模板时，如果使用自动推导，不会发生自动函数转换，即隐式函数转换
	int a = 10;
	int b = 20;
	char c = 'c';
	std::cout << myAdd01(a, c) << std::endl;//正确，将char类型的数据隐式转化为整型数据
	//myAdd02(a, c);//使用自动类型推导不会发生隐式类型转换
	myAdd02<int>(a, c);//使用显式指定类型可以发生隐式转换
}

//建议使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T
