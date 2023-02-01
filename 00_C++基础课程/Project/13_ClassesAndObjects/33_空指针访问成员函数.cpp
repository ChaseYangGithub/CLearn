#include<iostream>
using namespace std;

//空指针访问成员函数
//C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
//如果用到this指针，需要加以判断保证代码的健壮性

//兴趣类
class Interest {
public:
	void showClassName() {
		cout << "我是Interest类" << endl;
	}
	void showInterest() {
		if (this == NULL) {
			return;
		}
		//没有上面语句会报错
		cout << a << endl;
	}
public:
	int a;
};

//空指针访问成员函数测试类
void testNullPointer() {
	Interest *p=NULL;
	p->showClassName();//空指针，可以调用成员函数
	p->showInterest();//但是如果成员函数中用到了this指针，就不可以了

}