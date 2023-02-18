#include<iostream>
//����ģ���﷨
// ����ģ�����ã�
//����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ�����������������
//����ģ��-ͨ�ý�������

//�������ͺ���
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//���������ͺ���
void swapFloat(float& a, float& b) {
	float temp = a;
	a = b;
	b = temp;
}
/*
template  ---  ��������ģ��
typename  --- ��ʾ�����ķ�����һ���������ͣ�������class����
T    ---   ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ

* ����ģ�����ùؼ��� template
* ʹ�ú���ģ�������ַ�ʽ���Զ������Ƶ�����ʾָ������
* ģ���Ŀ����Ϊ����߸����ԣ������Ͳ�����
*/
//����ģ���ṩͨ�õĽ�������
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//ģ���������
void templateTest01() {
	int a = 5;
	int b = 10;
	//swapInt(a, b);

	//����ģ��ʵ��
	//1 �Զ�����ʵ��
	//mySwap(a, b);

	//2 ��ʽָ������
	mySwap<int>(a, b);

	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
}