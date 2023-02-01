#include<iostream>
using namespace std;

class Study {
public:
	Study() {
		cout << "Study构造函数" << endl;
	}
	~Study() {
		cout << "Study析构函数" << endl;
	}
};

class Learn :public Study{
public:
	Learn() {
		cout << "Learn构造函数" << endl;
	}
	~Learn() {
		cout << "Learn析构函数" << endl;
	}
};

void inheritTest2() {
	Learn l;//继承中先调用父类构造函数，在调用子类构造函数。析构与之相反

}