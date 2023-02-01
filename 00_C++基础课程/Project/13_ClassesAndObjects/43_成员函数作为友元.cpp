#include<iostream>
using namespace std;
class Building2;//提前声明类
class GoodGay2 {
public:
	GoodGay2();
	void visit();//只让visit函数作为Building的好朋友，可以发访问Building中私有内容
	void visit2();
private:
	Building2* build;
};

class Building2 {
	//告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
	friend void GoodGay2::visit();
public:
	Building2();
public:
	string sittingRoom;
private:
	string bedRoom;
};

//类外实现成员函数

Building2::Building2() {
	this->sittingRoom = "客厅";
	this->bedRoom = "卧室";
}

GoodGay2::GoodGay2() {
	//创建建筑物对象
	build = new Building2;
}
void GoodGay2::visit() {
	std::cout << "好基友访问:" << build->sittingRoom << endl;
	std::cout << "好基友访问:" << build->bedRoom << endl;
}
void GoodGay2::visit2() {
	std::cout << "好基友访问:" << build->sittingRoom << endl;
	//std::cout << "好基友访问:" << build->bedRoom << endl;
}
void friendTest3() {
	GoodGay2 good;
	good.visit();
}