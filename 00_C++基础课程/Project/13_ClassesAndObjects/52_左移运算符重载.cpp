#include<iostream>
using namespace std;

class Length {
	friend ostream& operator<<(ostream& out, Length& l);//������������������Ԫ����ʵ������Զ�����������
public:
	Length(int a, int b) {
		this->a = a;
		this->b = b;
	}

private:
	int a;
	int b;
};
//ȫ�ֺ���ʵ������
//ostream����ֻ��һ��
ostream& operator<<(ostream& out, Length& l) {
	out << "a:" << l.a << " b:" << l.b;
	return out;//���з���ֵ�ſ���ʹ����ʽ�������׷��
}

void operatorTest2() {
	Length l(10,10);
	cout << l << endl<<"hello world" << endl;//��ʽ���
}