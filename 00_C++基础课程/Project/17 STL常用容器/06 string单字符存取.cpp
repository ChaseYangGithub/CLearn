#include<iostream>
/*
* `char& operator[](int n); `     //通过[]方式取字符
* `char& at(int n);   `           //通过at方法获取字符
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
	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	std::cout << str << std::endl;
}