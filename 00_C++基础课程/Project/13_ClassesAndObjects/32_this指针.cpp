#include<iostream>
using namespace std;
//this指针

//高度类
class Height {
	//this指针是隐含每一个非静态成员函数内的一种指针
	//this指针不需要定义，直接使用即可
public:
	int h_a;
	Height() {

	}
	Height(int h_a) {
		//当形参和成员变量同名时，可用this指针来区分
		this->h_a = h_a;
	}
	Height& heightAddHeight(Height &h) {//要用引用传递返回值，如果使用值传递 链式传递会一直拷贝
		this->h_a += h.h_a;
		//返回对象本身
		return *this;
	}


};
//this指针测试
void thisTest() {
	Height h(21);
	cout << "h_a=" << h.h_a << endl;

	Height h2(3);
	//链式编程思想
	h2.heightAddHeight(h).heightAddHeight(h).heightAddHeight(h);
	cout << "p2 h_a=" << h2.h_a << endl;
}