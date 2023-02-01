#include<iostream>
using namespace std;

void Basic();
void Notice();
void ParameterReference();
void ReturnReference();
void EssenceOfReference();
void ConstReference();
//���õ����ã������������
int main() {
	//Basic();
	//Notice();
	//ParameterReference();
	//ReturnReference();
	//EssenceOfReference();
	ConstReference();

	system("pause");
}

//����ʹ��
void Basic() {
	//�﷨���������� &���� =ԭ����
	int a = 10;
	int& b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

}
//ע������
void Notice() {
	//���ñ����ʼ��
	//�����ڳ�ʼ���󲻿ɸ���
	int a = 10;
	int b = 20;
	//int& c;//���󣬱����ʼ��
	int& c = a;//һ����ʼ����㲻�ɸ�������
	c = b;	//��ֵ���������Ǹ������ã����Ըı�
	//&c = b;//���Ǹ������ã�����
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
//ֵ����
void SwapPassByValue(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
//��ַ����
void SwapPassByAddress(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//���ô���
void SwapPassByReference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//���a,b
void Output(int a, int b) {
	cout << "a=" << a << " b=" << b << endl;
}
//���ô���
void ParameterReference() {
//��������ʱ�������������õļ������β�����ʵ��
//���Լ�ָ���޸�ʵ��
//ͨ�����ò���������Ч��ͬ����ַ������һ���ġ����õ��﷨�������
	int a = 10;
	int b = 20;
	SwapPassByValue(a, b);
	Output(a, b);
	SwapPassByAddress(&a, &b);
	Output(a, b);
	SwapPassByReference(a, b);
	Output(a, b);
}
//���ؾֲ���������
int& LocalParameter() {
	int a = 10;//�ֲ�����
	return a;
}
//�����ĵ��ÿ�����Ϊ��ֵ
int& StaticLocalParameter() {
	static int a = 10;	//��̬��������ȫ������ȫ�����������ڳ��������ϵͳ�ͷ�
	return a;
}
//��������������ֵ
void ReturnReference() {
	//�����ǿ�����Ϊ�����ķ���ֵ���ڵ�
	//��Ҫ���ؾֲ�����������

	int& ref = LocalParameter();
	cout << "ref=" << ref;	//��ʱ���������˱���
	cout << "ref=" << ref;//��ʱ��ʱ�ռ䱻�ͷ��ˣ����ݱ�Ϊ���ֵ
	//�����ĵ��ÿ�����Ϊ��ֵ
	int& ref2 = StaticLocalParameter();
	cout << "ref2=" << ref2 << endl;
	cout << "ref2=" << ref2 << endl;
	//��������ķ���ֵ�����ã�����������ÿ�����Ϊ��ֵ
	StaticLocalParameter() = 1000;//�ȼ��� a=1000;
	cout << "ref2=" << StaticLocalParameter() << endl;
	cout << "ref2=" << StaticLocalParameter() << endl;
}
//���������ã�ת��Ϊ int* const ref = &a;
void func(int& ref) {
	ref = 100; // ref�����ã�ת��Ϊ*ref = 100
}
//���õı���
void EssenceOfReference() {
	//���õı�����c++�ڲ�ʵ����һ��ָ�볣��.
	//C++�Ƽ������ü�������Ϊ�﷨���㣬���ñ�����ָ�볣�����������е�ָ�����������������������

	int a = 10;

	//�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	int& ref = a;
	ref = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;
	func(a);
	cout << "ref:" << ref << endl; 
	cout << "ref:" << ref << endl;
}
//����ʹ�õĳ�����ͨ�����������β�
void ShowValue(const int& v) {
	//V += 10;//�����޸�
	cout << v << endl;
}
//��������
void ConstReference() {
	//����������Ҫ���������βΣ���ֹ�����
	//�ں����β��б��У����Լ�const�����βΣ���ֹ�βθı�ʵ��

	//int& ref = 10;  ���ñ�����Ҫһ���Ϸ����ڴ�ռ䣬������д���
	//����const�Ϳ����ˣ��������Ż����룬int temp = 10; const int& ref = temp;
	const int& ref = 10;
	//ref = 100;  //����const�󲻿����޸ı���
	cout << ref << endl;
	//���������ó������÷�ֹ������޸�ʵ��
	int a = 10;
	ShowValue(a);
}