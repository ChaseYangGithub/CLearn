#include<iostream>
/*
* `string substr(int pos = 0, int n = npos) const;`   //������pos��ʼ��n���ַ���ɵ��ַ���
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