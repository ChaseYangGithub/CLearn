<<<<<<< HEAD
#include<iostream>
using namespace std;
//C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
//函数占位参数
//占位参数只有参数类型声明，而没有参数名声明
//一般情况下，在函数体内部无法使用占位参数

//函数占位参数 ，占位参数也可以有默认参数
void Func(int a, int) {
	cout << "这里是func" << endl;
}
//函数占位符
void FunctionPlaceholder() {
	//Func(10);//不行。错误
	Func(10, 10);//占位符必须填补
=======
#include<iostream>
using namespace std;
//C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
//函数占位参数
//占位参数只有参数类型声明，而没有参数名声明
//一般情况下，在函数体内部无法使用占位参数

//函数占位参数 ，占位参数也可以有默认参数
void Func(int a, int) {
	cout << "这里是func" << endl;
}
//函数占位符
void FunctionPlaceholder() {
	//Func(10);//不行。错误
	Func(10, 10);//占位符必须填补
>>>>>>> 1238f1d7e05d405a3aa0d46eef22959aab388bd3
}