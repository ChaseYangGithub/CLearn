#include<iostream>

//��ͨ����
int myAdd01(int a, int b) {
	return a + b;
}

//����ģ��
template<class T>
T myAdd02(T a, T b) {
	return a + b;
}

//������ģ�庯��
void test14() {
	//ʹ�ú���ģ��ʱ�����ʹ���Զ��Ƶ������ᷢ���Զ�����ת��������ʽ����ת��
	int a = 10;
	int b = 20;
	char c = 'c';
	std::cout << myAdd01(a, c) << std::endl;//��ȷ����char���͵�������ʽת��Ϊ��������
	//myAdd02(a, c);//ʹ���Զ������Ƶ����ᷢ����ʽ����ת��
	myAdd02<int>(a, c);//ʹ����ʽָ�����Ϳ��Է�����ʽת��
}

//����ʹ����ʾָ�����͵ķ�ʽ�����ú���ģ�壬��Ϊ�����Լ�ȷ��ͨ������T
