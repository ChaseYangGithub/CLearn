#include<iostream>

//������ʹ��ʱ����������ͨ�����������ã������в������з���ֵ
class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};
//��������������Լ���״̬
class MyPrint {
public:
	MyPrint() {
		count = 0;
	}
	void operator()(std::string test) {
		std::cout << test;
		count++;//ͳ��ʹ�ô���
	}
public:
	int count;//�ڲ��Լ���״̬
};
//�������������Ϊ��������
void doPrint(MyPrint& m, std::string test) {
	m(test);
}

void test11() {
	MyAdd myAdd;
	std::cout << myAdd(10,10) << std::endl;
	MyPrint myPrint;
	myPrint("hello world!");
	myPrint("hello world!");
	myPrint("hello world!");
	myPrint("hello world!");
	std::cout << "���������" << myPrint.count << std::endl;

	doPrint(myPrint, "Hello C++");

}