#include<iostream>
using namespace std;
//全局函数作为友元
//有元的关键字是friend

//建筑类
class Building {
	//告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
	friend void goodGay(Building& build);

public:
	Building() {
		sittingRoom = "客厅";
		bedRoom = "卧室";
	}
public:
	string sittingRoom;//客厅
private:
	string bedRoom;//卧室
};

//好基友--全局函数作为友元
void goodGay(Building &build) {
	cout << "好基友正在访问：" << build.sittingRoom << endl;
	cout << "好基友正在访问：" << build.bedRoom << endl;//需要是友元才能访问
}

void friendTest() {
	Building build;
	goodGay(build);
}