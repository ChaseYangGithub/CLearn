#include<iostream>
/*
* `char& operator[](int n); `     //ͨ��[]��ʽȡ�ַ�
* `char& at(int n);   `           //ͨ��at������ȡ�ַ�
*/

void test06() {
	std::string str = "hello world";
	for (int i = 0; i < str.size(); i++) {
		std::cout << str[i] << " ";
	}
	std::cout << std::endl;
	for (int i = -0; i < str.size(); i++) {
		std::cout << str.at(i) << " ";
	}
	std::cout << std::endl;
	//�ַ��޸�
	str[0] = 'x';
	str.at(1) = 'x';
	std::cout << str << std::endl;
}