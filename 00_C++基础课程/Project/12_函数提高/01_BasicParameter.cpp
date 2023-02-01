#include<iostream>
using namespace std;
//函数的默认参数
//在C++中，函数的形参列表中的形参是可以有默认值的。
//如果自己传入数据就用自己的，没传入数据就用默认值

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
int Func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
//声明和实现只能有一个有默认参数
int Func2(int a = 10, int b = 10);
int Func2(int a, int b) {
	return a + b;
}
//函数的默认参数
void BasicParameter() {
	//有默认值的时候参数可以不赋值
	cout << "ret=" << Func(20, 20) << endl;
	cout << "ret=" << Func(100) << endl;
	cout << "ret=" << Func2() << endl;
}