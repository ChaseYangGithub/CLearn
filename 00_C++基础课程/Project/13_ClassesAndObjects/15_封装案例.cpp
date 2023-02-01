#include<iostream>
using namespace std;

/*
�����������(Cube)

������������������

�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�
*/

//��������
class Cube {
private:
	double l;//��
	double w;//��
	double h;//��
public:
	//���ó�
	void SetL(double len) {
		l = len;
	}
	double getL() {
		return l;
	}
	//���ÿ�
	void setW(double width) {
		w = width;
	}
	double getW() {
		return w;
	}
	//���ø�
	void setH(double height) {
		h = height;
	}
	double getH() {
		return h;
	}
	//�����
	double area() {
		return 2 * (l * w + l * h + w * h);
	}
	//�����
	double volume() {
		return l * w * h;
	}
	//�ж����
	//������������ȵ�����ʱ����������������߶����������
	//ֻҪ�����ȼ����������߷ֱ���������������
	void equal(Cube& another) {
		//����
		double L = another.getL();
		double W = another.getW();
		double H = another.getH();
		//���ֵ
		double tep1 = l > w ? l : w;
		double tep2 = tep1 > h ? tep1 : h;
		double tep3 = L > W ? L : W;
		double tep4 = tep3 > H ? tep3 : H;
		if (tep2 == l) {//���ֵ�ڵ�һ�αȽ��У���Ҫ�ٴαȽ��ҵڶ�������
			tep1 = w > h ? w : h;
		}
		else if (tep2 == w) {
			tep1 = l > h ? l : h;
		}
		if (tep4 == L) {//���ֵ�ڵ�һ�αȽ��У���Ҫ�ٴαȽ��ҵڶ�������
			tep3 = W > H ? W : H;
		}
		else if (tep4 == W) {
			tep3 = L > H ? L : H;
		}
		if (tep1 == tep3 && tep2 == tep4 && l * w * h == L * W * H) {
			cout << "�ڲ� ��������������  ��ȣ�" << endl;
		}
		else {
			cout << "�ڲ� ��������������  ����ȣ�" << endl;
		}
	}
};

//ȫ�ֺ������ж�����Բ�Ƿ����
//���������ֵ���ڶ����ֵ��ʵ�������������ȽϷ���
void equal(Cube& c, Cube& d) {
	//����
	double l = c.getL();
	double w = c.getW();
	double h= c.getH();
	double L = d.getL();
	double H = d.getH();
	double W = d.getW();
	//���ֵ
	double tep1 = l > w ? l : w;
	double tep2 = tep1 > h ? tep1 : h;
	double tep3 = L > W ? L : W;
	double tep4 = tep3 > H ? tep3 : H;
	if (tep2 == l) {//���ֵ�ڵ�һ�αȽ��У���Ҫ�ٴαȽ��ҵڶ�������
		tep1 = w > h ? w : h;
	}
	else if (tep2 == w) {
		tep1 = l > h ? l : h;
	}
	if (tep4 == L) {//���ֵ�ڵ�һ�αȽ��У���Ҫ�ٴαȽ��ҵڶ�������
		tep3 = W > H ? W : H;
	}
	else if (tep4 == W) {
		tep3 = L > H ? L : H;
	}
	if (tep1 == tep3 && tep2 == tep4 && l * w * h == L * W * H) {
		cout << "ȫ�� ��������������  ��ȣ�" << endl;
	}
	else {
		cout << "ȫ�� ��������������  ����ȣ�" << endl;
	}
}
//��װ����--������
void caseCube() {
	Cube* c = new Cube();
	c->SetL(10);
	c->setH(20);
	c->setW(5);
	double area = c->area();
	cout << "Բ�������" << area << endl;
	double volume = c->volume();
	cout << "Բ�������" << volume << endl;
	Cube * another = new Cube();
	another->SetL(20);
	another->setH(5);
	another->setW(10);
	//�ڲ�
	c->equal(*another);
	//ȫ��
	equal(*c, *another);
}