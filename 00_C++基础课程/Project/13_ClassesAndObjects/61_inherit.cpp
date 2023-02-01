#include<iostream>
using namespace std;

//继承基本概念

//基类
class BasicPage {
public:
	void header() {
		cout << "公共头部" << endl;
	}
	void sidebar() {
		cout << "公共侧栏" << endl;
	}
	void footer() {
		cout << "公共底部" << endl;
	}
};

//继承语法：class A : public B; 
//python子类
class Python:public BasicPage {
public:
	void content() {
		cout << "Python" << endl;
	}
};
//Java类
class Java :public BasicPage {
public:
	void content() {
		cout << "Java" << endl;
	}
};

void inherit() {
	//Java页面
	cout << "Java页面如下： " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.sidebar();
	ja.content();
	cout << "--------------------" << endl;

	//Python页面
	cout << "Python页面如下： " << endl;
	Python py;
	py.header();
	py.footer();
	py.sidebar();
	py.content();
	cout << "--------------------" << endl;

}

