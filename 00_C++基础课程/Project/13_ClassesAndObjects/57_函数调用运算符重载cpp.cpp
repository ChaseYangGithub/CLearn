#include<iostream>
using namespace std;

//�����������������

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
	query.operator()("�����������ǳ�");
	Range range;
	int add = range.operator()(10, 10);
	cout << "add=" << add<<endl;
	//�����������
	cout << Range()(20, 20) << endl;
	cout <<Query()("������������ҹ�������������")<<endl;

}
