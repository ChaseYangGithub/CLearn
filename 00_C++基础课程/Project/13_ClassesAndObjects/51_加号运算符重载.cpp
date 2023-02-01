#include<iostream>
using namespace std;
//��������ظ�������е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
//�ܽ�1���������õ��������͵ı��ʽ�ĵ�������ǲ����ܸı��
//�ܽ�2����Ҫ�������������

//�Ӻ����������
//���ã�ʵ�������Զ�������������ӵ�����
class Key {
public:
	Key() {};
	Key(int a, int b) {
		this->a = a;
		this->b = b;
	}
	//��Ա����ʵ��+�����������
	Key operator+(const Key& k) {
		Key temp;
		temp.a = this->a + k.a;
		temp.b = this->b + k.b;
		return temp;
	}
public:
	int a;
	int b;
};
//ȫ�ֺ���ʵ��+�ź�������
Key operator+(const Key& p, const Key& q) {
	Key temp;
	temp.a = p.a + q.a;
	temp.b = p.b + q.b;
	return temp;
}

//��������ؿ��Է�����������
Key operator+(const Key& p, int val) {
	Key temp;
	temp.a = p.a + val;
	temp.b = p.b + val;
	return temp;
}

void operatorTest(){
	Key p(1, 10);
	Key q(10, 100);
	//��Ա������ʽ
	Key t = p + q;//�ȼ���p.operator(q)
	cout << "a:" << t.a << " b:" << t.b << endl;

	Key t2 = p + 10;//�ȼ���operator(p,10)
	cout << "a:" << t2.a << " b:" << t2.b <<endl;

	Key t3 = p + q;//�ȼ���operator(p,q)
	cout << "a:" << t3.a << " b:" << t3.b << endl;


}