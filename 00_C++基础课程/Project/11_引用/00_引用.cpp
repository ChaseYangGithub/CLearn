#include<iostream>
using namespace std;

void Basic();
void Notice();
void ParameterReference();
void ReturnReference();
void EssenceOfReference();
void ConstReference();
//引用的作用：给变量起别名
int main() {
	//Basic();
	//Notice();
	//ParameterReference();
	//ReturnReference();
	//EssenceOfReference();
	ConstReference();

	system("pause");
}

//基本使用
void Basic() {
	//语法：数据类型 &别名 =原名；
	int a = 10;
	int& b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

}
//注意事项
void Notice() {
	//引用必须初始化
	//引用在初始化后不可更改
	int a = 10;
	int b = 20;
	//int& c;//错误，必须初始化
	int& c = a;//一旦初始化后便不可更改引用
	c = b;	//赋值操作，不是更改引用，可以改变
	//&c = b;//这是更改引用，错误
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
//值传递
void SwapPassByValue(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
//地址传递
void SwapPassByAddress(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//引用传递
void SwapPassByReference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//输出a,b
void Output(int a, int b) {
	cout << "a=" << a << " b=" << b << endl;
}
//引用传参
void ParameterReference() {
//函数传参时，可以利用引用的技术让形参修饰实参
//可以简化指针修改实参
//通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单
	int a = 10;
	int b = 20;
	SwapPassByValue(a, b);
	Output(a, b);
	SwapPassByAddress(&a, &b);
	Output(a, b);
	SwapPassByReference(a, b);
	Output(a, b);
}
//返回局部变量引用
int& LocalParameter() {
	int a = 10;//局部变量
	return a;
}
//函数的调用可以作为左值
int& StaticLocalParameter() {
	static int a = 10;	//静态变量存在全局区，全局区的数据在程序结束后系统释放
	return a;
}
//引用作函数返回值
void ReturnReference() {
	//引用是可以作为函数的返回值存在的
	//不要返回局部变量的引用

	int& ref = LocalParameter();
	cout << "ref=" << ref;	//此时编译器做了保留
	cout << "ref=" << ref;//此时临时空间被释放了，内容变为随机值
	//函数的调用可以作为左值
	int& ref2 = StaticLocalParameter();
	cout << "ref2=" << ref2 << endl;
	cout << "ref2=" << ref2 << endl;
	//如果函数的返回值是引用，这个函数调用可以作为左值
	StaticLocalParameter() = 1000;//等价于 a=1000;
	cout << "ref2=" << StaticLocalParameter() << endl;
	cout << "ref2=" << StaticLocalParameter() << endl;
}
//发现是引用，转换为 int* const ref = &a;
void func(int& ref) {
	ref = 100; // ref是引用，转换为*ref = 100
}
//引用的本质
void EssenceOfReference() {
	//引用的本质在c++内部实现是一个指针常量.
	//C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了

	int a = 10;

	//自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	int& ref = a;
	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;
	func(a);
	cout << "ref:" << ref << endl; 
	cout << "ref:" << ref << endl;
}
//引用使用的场景，通常用于修饰形参
void ShowValue(const int& v) {
	//V += 10;//不可修改
	cout << v << endl;
}
//常量引用
void ConstReference() {
	//常量引用主要用来修饰形参，防止误操作
	//在函数形参列表中，可以加const修饰形参，防止形参改变实参

	//int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
	//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
	const int& ref = 10;
	//ref = 100;  //加入const后不可以修改变量
	cout << ref << endl;
	//函数中利用常量引用防止误操作修改实参
	int a = 10;
	ShowValue(a);
}