#include<iostream>
using namespace std;
#include "00_����.h"
/*
���ã�������������ͬ����߸�����

����������������������
	ͬһ��������
	����������ͬ
	����������ͬ���߸�����ͬ����˳��ͬ

���������ķ���ֵ������Ϊ�������ص�����
*/

void Func() {
	cout << "Func�ĵ���" << endl;
}
void Func(int a) {
	cout << "Func(int a)�ĵ���" << endl;
}
void Func(int a, int b,int c) {
	cout << "Func(int a,int b,int c)�ĵ���" << endl;
}
void Func(double a) {
	cout << "Func(double a)�ĵ���" << endl;
}

//��������ֵ��������Ϊ������������
//int Func() {
//	cout << "int Func�ĵ���" << endl;
//	return 1;
//}

//��������
void FunctionOverload() {
	Func();
	Func(1);
	Func(1, 2,3);
	Func(2.0);
}

//1��������Ϊ��������
void Case1(int& a) {
	cout << "Case1(int &a)�ĵ���" << endl;
}
//1��������Ϊ��������
void Case1(const int& a) {
	cout << "Case1(const int &a)�ĵ���" << endl;
}
//����������������Ĭ�ϲ���
void Case2(int a) {
	cout << "Case2(int a)��������" << endl;
}
//����������������Ĭ�ϲ���
void Case2(int a, int b = 10) {
	cout << "Case2(int a,int b=10)�ĵ���" << endl;
}


//��������ע������
void Notice() {
	int a = 10;
	Case1(a);//������const
	Case1(10);//������const ��ʱ��const����Ϊ int &a=10���Ϸ�����const int &a�Ϸ�����ϸ������const���֣�
	//Case2(a);//����Ĭ�ϲ�����������
}