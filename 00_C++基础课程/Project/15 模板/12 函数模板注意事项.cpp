#include<iostream>
template<class T>//typename����ʹ��class����
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
void func() {
	std::cout << "func����" << std::endl;
}
//ģ��ע���������
void test12() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//1���Զ������Ƶ��������Ƶ���һ�µ���������T, �ſ���ʹ��
	mySwap(a, b);
	//mySwap(a, c);//�Ƶ�����һ�µ���������

	//2 ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
	//func();//ģ�岻�ܶ���ʹ�ã�����ȷ��T����������
	func<int>();//������ʾָ�����͵ķ�ʽ��Tһ���������ͣ��ſ���ʹ�ø�ģ��


}