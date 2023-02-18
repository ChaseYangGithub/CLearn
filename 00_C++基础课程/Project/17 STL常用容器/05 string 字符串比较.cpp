#include<iostream>
/*
int compare(const string&s) const;//与字符串s比较
int compare(const char *s) const;//与字符串比较
*/

void test05() {
	std::string s1 = "hello";
	std::string s2 = "aello";
	int ret = s1.compare(s2);
	if (ret == 0) {
		std::cout << "s1 等于s2";
	}
	else if (ret > 0) {
		std::cout << "s1 >s2" << std::endl;
	}
	else {
		std::cout << "s1<s2" << std::endl;
	}
}