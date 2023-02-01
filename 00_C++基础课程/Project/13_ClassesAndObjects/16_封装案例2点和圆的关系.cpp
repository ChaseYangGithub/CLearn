#include<iostream>
using namespace std;

//设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。

//圆类
class Circle {
private:
	double r;//半径
	double x;//坐标x
	double y;//坐标y
public:
	//半径
	void setR(double range) {
		r = range;
	}
	double getR() {
		return r;
	}
	//X坐标
	void setX(double xpos) {
		x = xpos;
	}
	double getX() {
		return x;
	}
	//Y坐标
	void setY(double ypos) {
		y = ypos;
	}
	double getY() {
		return y;
	}
};
//点类
class Point {
private:
	double x;//x坐标
	double y;//y坐标
public:
	void setX(double xpos) {
		x = xpos;
	}
	double getX() {
		return x;
	}
	//Y坐标
	void setY(double ypos) {
		y = ypos;
	}
	double getY() {
		return y;
	}
};

//点和圆的关系
//只要两点距离的平方小于半径的平方在圆内，等于在圆上，大于在圆外侧
void relation(Circle& c, Point& p) {
	double x = c.getX() - p.getX();
	double y = c.getY() - p.getY();
	double s2 = x * x + y * y;
	double r2 = c.getR() * c.getR();
	if (s2 < r2) {
		cout << "点在圆内！" << endl;
	}
	else if (s2 == r2) {
		cout << "点在圆上" << endl;
	}
	else {
		cout << "点在圆外" << endl;
	}
}
//点与圆之间的关系测试
void relationBCP() {
	Circle* c = new Circle();
	c->setR(5);
	c->setX(0);
	c->setY(0);
	Point* p = new Point();
	p->setX(1);
	p->setY(4);
	relation(*c, *p);
}