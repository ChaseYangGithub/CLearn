#include<iostream>

//函数在使用时，可以想普通函数那样调用，可以有参数，有返回值
class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};
//函数对象可以有自己的状态
class MyPrint {
public:
	MyPrint() {
		count = 0;
	}
	void operator()(std::string test) {
		std::cout << test;
		count++;//统计使用次数
	}
public:
	int count;//内部自己的状态
};
//函数对象可以最为参数传递
void doPrint(MyPrint& m, std::string test) {
	m(test);
}

void test11() {
	MyAdd myAdd;
	std::cout << myAdd(10,10) << std::endl;
	MyPrint myPrint;
	myPrint("hello world!");
	myPrint("hello world!");
	myPrint("hello world!");
	myPrint("hello world!");
	std::cout << "输出次数：" << myPrint.count << std::endl;

	doPrint(myPrint, "Hello C++");

}