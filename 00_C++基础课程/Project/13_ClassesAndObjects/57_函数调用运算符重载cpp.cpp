#include<iostream>
using namespace std;

//函数调用运算符重载

class Query {
public:
	string operator()(string text) {
		cout << text << endl;
		return text;
	}
};

class Range {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

void operatorTest7() {
	Query query;
	query.operator()("我曾触摸过星辰");
	Range range;
	int add = range.operator()(10, 10);
	cout << "add=" << add<<endl;
	//匿名对象调用
	cout << Range()(20, 20) << endl;
	cout <<Query()("你是我漫长黑夜里的迷恋与遗忘")<<endl;

}
