#include<iostream>
using namespace std;

/*
设计立方体类(Cube)

求出立方体的面积和体积

分别用全局函数和成员函数判断两个立方体是否相等。
*/

//立方体类
class Cube {
private:
	double l;//长
	double w;//宽
	double h;//高
public:
	//设置长
	void SetL(double len) {
		l = len;
	}
	double getL() {
		return l;
	}
	//设置宽
	void setW(double width) {
		w = width;
	}
	double getW() {
		return w;
	}
	//设置高
	void setH(double height) {
		h = height;
	}
	double getH() {
		return h;
	}
	//求面积
	double area() {
		return 2 * (l * w + l * h + w * h);
	}
	//求体积
	double volume() {
		return l * w * h;
	}
	//判断相等
	//两个立方体相等的条件时长宽高三个数据两者都存在且相等
	//只要体积相等及最大的两个边分别相等则立方体相等
	void equal(Cube& another) {
		//参数
		double L = another.getL();
		double W = another.getW();
		double H = another.getH();
		//最大值
		double tep1 = l > w ? l : w;
		double tep2 = tep1 > h ? tep1 : h;
		double tep3 = L > W ? L : W;
		double tep4 = tep3 > H ? tep3 : H;
		if (tep2 == l) {//最大值在第一次比较中，需要再次比较找第二大数据
			tep1 = w > h ? w : h;
		}
		else if (tep2 == w) {
			tep1 = l > h ? l : h;
		}
		if (tep4 == L) {//最大值在第一次比较中，需要再次比较找第二大数据
			tep3 = W > H ? W : H;
		}
		else if (tep4 == W) {
			tep3 = L > H ? L : H;
		}
		if (tep1 == tep3 && tep2 == tep4 && l * w * h == L * W * H) {
			cout << "内部 函数两个立方体  相等！" << endl;
		}
		else {
			cout << "内部 函数两个立方体  不相等！" << endl;
		}
	}
};

//全局函数，判断两个圆是否相等
//对于求最大值，第二大的值其实单独建立函数比较方便
void equal(Cube& c, Cube& d) {
	//变量
	double l = c.getL();
	double w = c.getW();
	double h= c.getH();
	double L = d.getL();
	double H = d.getH();
	double W = d.getW();
	//最大值
	double tep1 = l > w ? l : w;
	double tep2 = tep1 > h ? tep1 : h;
	double tep3 = L > W ? L : W;
	double tep4 = tep3 > H ? tep3 : H;
	if (tep2 == l) {//最大值在第一次比较中，需要再次比较找第二大数据
		tep1 = w > h ? w : h;
	}
	else if (tep2 == w) {
		tep1 = l > h ? l : h;
	}
	if (tep4 == L) {//最大值在第一次比较中，需要再次比较找第二大数据
		tep3 = W > H ? W : H;
	}
	else if (tep4 == W) {
		tep3 = L > H ? L : H;
	}
	if (tep1 == tep3 && tep2 == tep4 && l * w * h == L * W * H) {
		cout << "全局 函数两个立方体  相等！" << endl;
	}
	else {
		cout << "全局 函数两个立方体  不相等！" << endl;
	}
}
//封装案例--正方体
void caseCube() {
	Cube* c = new Cube();
	c->SetL(10);
	c->setH(20);
	c->setW(5);
	double area = c->area();
	cout << "圆的面积：" << area << endl;
	double volume = c->volume();
	cout << "圆的体积：" << volume << endl;
	Cube * another = new Cube();
	another->SetL(20);
	another->setH(5);
	another->setW(10);
	//内部
	c->equal(*another);
	//全局
	equal(*c, *another);
}