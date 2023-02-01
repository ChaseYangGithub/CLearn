#include<iostream>
using namespace std;

class Mess {
	friend ostream& operator<<(ostream& out, Mess mess);
public:
	Mess() {
		this->duck = 0;
	}
	//前置++ 先+后返回 返回引用是为了一直对一个数据进行输出
	Mess& operator++() {
		duck++;
		return *this;
	}
	//后置++ 先返回再赋值
	Mess operator++(int) { //int代表占位参数，可以用于区分参数和后置参数
		Mess temp = *this;//记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		duck++;
		return temp;
	}
private:
	int duck;
};
ostream& operator<<(ostream& out, Mess mess) {
	out << mess.duck;
	return out;
}

void operatorTest3() {
	Mess mess;
	cout << ++mess << endl;
	cout << mess << endl;
	cout <<mess++ << endl;
	cout << mess << endl;
}