#include<iostream>
using namespace std;
//������������ʱ��
/*
C++ʹ�ÿ�������ͨ�����������
	ʹ��һ��һ������ϵĶ�������ʼ��һ���¶���
	ֵ���ݵķ�ʽ��������������ֵ
	��ֵ���ݵķ�ʽ���ؾֲ�����
*/

//ƻ����
class Apple {
public:
	Apple() {
		cout << "�޲ι��캯����" << endl;
	}
	Apple(int a) {
		cout << "�вι��캯��" << endl;
	}
	Apple(const Apple& a) {
		cout << "�������캯��" << endl;
	}
	//�����������ͷ��ڴ�ǰ����
	~Apple() {
		cout << "��������" << endl;
	}
public:
	int size;
};

//ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01() {
	Apple a(10);	//a���󴴽����
	Apple newa(a);//���ÿ������캯��1
	Apple newa2 = a;//��������2
}
//�ȼ���Apple a1=a;
void doWork(Apple a1) {}
//ֵ���ݵķ�ʽ������������ֵ
void test02() {
	Apple a;
	doWork(a);
}
//��ֵ��ʽ���ؾֲ�����
Apple doWork2() {
	Apple a1;
	cout << (int*)&a1 << endl;
	return a1;
}
void test03() {
	Apple a = doWork2();
	cout << (int*)&a << endl;

}
//������������ʱ������
void copyConstructor() {
	cout << "ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���µĶ���" << endl;
	test01();
	cout << "ֵ���ݵķ�������������ֵ" << endl;
	test02();
	cout << "��ֵ��ʽ���ؾֲ�����" << endl;
	test03();//���ں����ڲ����ⲿ����Ϊ������ϵ����ַ������ͬ
} 