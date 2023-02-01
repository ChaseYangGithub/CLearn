#include<iostream>
using namespace std;

class Ops {
public:
	Ops(int age) {
		//将年龄数据放到堆区
		mage = new int(age);
	}
	//重载赋值运算符
	Ops& operator=(Ops& p) {
		if (mage !=NULL) {
			delete mage;
			mage = NULL;
		}
		//编译器提供的浅拷贝代码
		//mage = p.mage;

		//提供深拷贝，解决浅拷贝的问题
		mage = new int(*p.mage);
		//返回自身
		return *this;
	}

	//析构函数
	~Ops() {
		if (mage != NULL) {
			delete mage;
			mage = NULL;
		}
	}
	int *mage;
};


void operatorTest5() {
	Ops p1(10);
	Ops p2(20);
	Ops p3(30);
	p3 = p2 = p1;
	cout << "p1:" <<*p1.mage << endl;
	cout << "p2:" <<*p2.mage << endl;
	cout << "p3:" <<*p3.mage << endl;
}