#include<iostream>
using namespace std;

//���캯���ķ��༰����
/*
���캯���ķ��ࣺ
	��������Ϊ���вι�����޲ι���
	�����ͷ�Ϊ����ͨ����Ϳ�������
���ֵ��÷�ʽ��
	���ŷ�
	��ʾ��
	��ʽת����
*/

//����
class Human {
public:
	int age;
public:
	//�޲�(Ĭ�ϣ����캯��
	Human() {
		cout << "�޲ι��캯��" << endl;
	}
	//�вι��캯��
	Human(int a) {
		cout << "�вι��캯��" << endl;
	}
	//�������캯��
	Human(const Human& p) {
		age = p.age;
		cout << "�������캯��" << endl;
	}
	//��������
	~Human() {
		cout << "��������" << endl;
	}
};

//2.���캯���ĵ���

//�����޲ι��캯��
void test1() {
	Human h;//�����޲ι��캯��
}
//�����вι��캯��
void test2() {
	//1���ŷ�����
	Human h1(20);
	//�����޲ι��캯�����ܼ����ţ���������ű���������Ϊ�Ǻ�������
	//Human h2();

	//��ʾ��
	Human h2 = Human(10);
	Human h3 = Human(h2);//��������
	//Human(10)����д���������� ����Ϊ��������������

	//��ʽת����
	Human h4 = 10;	//�ȼ��� Human h4 =Human(10)
	Human h5 = h4;	//��������

	//����ʹ�ÿ������캯������ʼ���������󣬱���������Ϊ�Ƕ������� Human (h5)==Human h5
	//Human(h5);
}


//���캯���ķ��༰����
void constructionClassification() {
	test1();//�����޲κ���
	test2();//�����вκ���
}
