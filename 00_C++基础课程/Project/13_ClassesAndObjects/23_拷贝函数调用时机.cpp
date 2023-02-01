#include<iostream>
using namespace std;
//拷贝函数调用时机
/*
C++使用拷贝函数通常有三种情况
	使用一个一创建完毕的对象来初始化一个新对象
	值传递的方式来给函数参数传值
	以值传递的方式返回局部变量
*/

//苹果类
class Apple {
public:
	Apple() {
		cout << "无参构造函数！" << endl;
	}
	Apple(int a) {
		cout << "有参构造函数" << endl;
	}
	Apple(const Apple& a) {
		cout << "拷贝构造函数" << endl;
	}
	//析构函数在释放内存前调用
	~Apple() {
		cout << "析构函数" << endl;
	}
public:
	int size;
};

//使用一个已经创建完毕的对象来初始化一个新对象
void test01() {
	Apple a(10);	//a对象创建完毕
	Apple newa(a);//调用拷贝构造函数1
	Apple newa2 = a;//拷贝构造2
}
//等价于Apple a1=a;
void doWork(Apple a1) {}
//值传递的方式给函数参数传值
void test02() {
	Apple a;
	doWork(a);
}
//以值方式返回局部对象
Apple doWork2() {
	Apple a1;
	cout << (int*)&a1 << endl;
	return a1;
}
void test03() {
	Apple a = doWork2();
	cout << (int*)&a << endl;

}
//拷贝函数调用时机测试
void copyConstructor() {
	cout << "使用一个已经创建完毕的对象来初始化一个新的对象" << endl;
	test01();
	cout << "值传递的方给函数参数传值" << endl;
	test02();
	cout << "以值方式返回局部对象" << endl;
	test03();//由于函数内部和外部对象为拷贝关系，地址并不相同
} 