#include<iostream>
using namespace std;
class Buildings;//提前声明类
class GoodGay {
public:
	GoodGay();
	void visit();
private:
	Buildings *build;
};

class Buildings {
	//告诉编译器 GoodGay类是Building类的好朋友，可以访问到Building类中私有内容
	friend class GoodGay;
public:
	Buildings();
public:
	string sittingRoom;
private:
	string bedRoom;
};

//类外实现成员函数

Buildings::Buildings() {
	this->sittingRoom = "客厅";
	this->bedRoom = "卧室";
}

GoodGay::GoodGay() {
	//创建建筑物对象
	build = new Buildings;
}
void GoodGay::visit() {
	std::cout << "好基友访问:" << build->sittingRoom << endl;
	std::cout << "好基友访问:" << build->bedRoom << endl;
}
void friendTest2() {
	GoodGay good;
	good.visit();
}