#include<iostream>
using namespace std;

//���һ��Բ���ࣨCircle������һ�����ࣨPoint����������Բ�Ĺ�ϵ��

//Բ��
class Circle {
private:
	double r;//�뾶
	double x;//����x
	double y;//����y
public:
	//�뾶
	void setR(double range) {
		r = range;
	}
	double getR() {
		return r;
	}
	//X����
	void setX(double xpos) {
		x = xpos;
	}
	double getX() {
		return x;
	}
	//Y����
	void setY(double ypos) {
		y = ypos;
	}
	double getY() {
		return y;
	}
};
//����
class Point {
private:
	double x;//x����
	double y;//y����
public:
	void setX(double xpos) {
		x = xpos;
	}
	double getX() {
		return x;
	}
	//Y����
	void setY(double ypos) {
		y = ypos;
	}
	double getY() {
		return y;
	}
};

//���Բ�Ĺ�ϵ
//ֻҪ��������ƽ��С�ڰ뾶��ƽ����Բ�ڣ�������Բ�ϣ�������Բ���
void relation(Circle& c, Point& p) {
	double x = c.getX() - p.getX();
	double y = c.getY() - p.getY();
	double s2 = x * x + y * y;
	double r2 = c.getR() * c.getR();
	if (s2 < r2) {
		cout << "����Բ�ڣ�" << endl;
	}
	else if (s2 == r2) {
		cout << "����Բ��" << endl;
	}
	else {
		cout << "����Բ��" << endl;
	}
}
//����Բ֮��Ĺ�ϵ����
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