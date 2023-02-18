#include<iostream>
/*
* `string substr(int pos = 0, int n = npos) const;`   //返回由pos开始的n个字符组成的字符串
*/

void test08() {
	std::string str = "I love You,But you love him";
	std::string str2 = str.substr(0, 10);
	std::cout << str2 << std::endl;

	str = "yangchaseyang@gmail.com";
	int pos = str.find('@');
	std::string username = str.substr(0, pos);
	std::cout << username << std::endl;
}