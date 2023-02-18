#include<iostream>
template<class T>//typename可以使用class代替
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
void func() {
	std::cout << "func调用" << std::endl;
}
//模板注意事项测试
void test12() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//1、自动类型推导，必须推导出一致的数据类型T, 才可以使用
	mySwap(a, b);
	//mySwap(a, c);//推导出不一致的数据类型

	//2 模板必须要确定出T的数据类型，才可以使用
	//func();//模板不能独立使用，必须确定T的数据类型
	func<int>();//利用显示指定类型的方式给T一个数据类型，才可以使用该模板


}