#include<iostream>
using namespace std;
//������Ĭ�ϲ���
//��C++�У��������β��б��е��β��ǿ�����Ĭ��ֵ�ġ�
//����Լ��������ݾ����Լ��ģ�û�������ݾ���Ĭ��ֵ

//1. ���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ�����󣬴������ң����붼Ҫ��Ĭ��ֵ
int Func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//2. �������������Ĭ��ֵ������ʵ�ֵ�ʱ��Ͳ�����Ĭ�ϲ���
//������ʵ��ֻ����һ����Ĭ�ϲ���
int Func2(int a = 10, int b = 10);
int Func2(int a, int b) {
	return a + b;
}
//������Ĭ�ϲ���
void BasicParameter() {
	//��Ĭ��ֵ��ʱ��������Բ���ֵ
	cout << "ret=" << Func(20, 20) << endl;
	cout << "ret=" << Func(100) << endl;
	cout << "ret=" << Func2() << endl;
}