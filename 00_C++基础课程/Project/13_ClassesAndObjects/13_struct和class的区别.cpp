#include<iostream>
using namespace std;

/*
	��C++��struct��class��Ψһ���������Ĭ�ϵķ���Ȩ�޲�ͬ
	����
		structĬ�Ϸ���Ȩ��Ϊ����
		classĬ��Ȩ��Ϊ˽��
*/

class C1 {
	int a;	//Ĭ����˽��Ȩ��
};
struct C2 {
	int a;//Ĭ���ǹ���Ȩ��
};

void diffInStructAndClass() {
	//C1 c1;
	C2 c2;
	//c1.a = 10;//���󣬷���Ȩ����˽��
	c2.a = 20;//����Ȩ���ǹ���
}