#include<iostream>
/*
int compare(const string&s) const;//���ַ���s�Ƚ�
int compare(const char *s) const;//���ַ����Ƚ�
*/

void test05() {
	std::string s1 = "hello";
	std::string s2 = "aello";
	int ret = s1.compare(s2);
	if (ret == 0) {
		std::cout << "s1 ����s2";
	}
	else if (ret > 0) {
		std::cout << "s1 >s2" << std::endl;
	}
	else {
		std::cout << "s1<s2" << std::endl;
	}
}