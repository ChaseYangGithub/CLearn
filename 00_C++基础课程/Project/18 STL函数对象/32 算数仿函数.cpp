#include<iostream>
#include<functional>//�ڽ���������
//�����º��� ʵ����������
void test32() {
	//ȡ���º���
	std::negate<int> n;
	std::cout << n(50) << std::endl;
	//�ӷ��º���
	std::plus<int> p;
	std::cout << p(10, 20) << std::endl;
	//ȡģ�º���
	std::modulus<int> m;
	std::cout << m(10, 6) << std::endl;
}