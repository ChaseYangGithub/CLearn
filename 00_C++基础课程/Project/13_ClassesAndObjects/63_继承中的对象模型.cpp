#include<iostream>
using namespace std;
//�̳��еĶ���ģ��

class Base {
public:
	int a;
protected:
	int b;
private:
	int c;//˽�г�Աֻ�Ǳ����أ����ǻ��ǻᱻ�̳���ȥ
};

//�����̳�
class Son :public Base {
public:
	int d;
};

void inheritTest() {
	cout << "sizeof Son=" << sizeof(Son) << endl;//�˴���СΪ16
}