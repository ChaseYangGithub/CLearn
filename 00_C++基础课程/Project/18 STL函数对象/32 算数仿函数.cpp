#include<iostream>
#include<functional>//内建函数对象
//算数仿函数 实现四则运算
void test32() {
	//取反仿函数
	std::negate<int> n;
	std::cout << n(50) << std::endl;
	//加法仿函数
	std::plus<int> p;
	std::cout << p(10, 20) << std::endl;
	//取模仿函数
	std::modulus<int> m;
	std::cout << m(10, 6) << std::endl;
}