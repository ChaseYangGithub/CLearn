#include<iostream>
/*
* `string& operator+=(const char* str);`                   //重载+=操作符
* `string& operator+=(const char c);`                         //重载+=操作符
* `string& operator+=(const string& str);`                //重载+=操作符
* `string& append(const char *s); `                               //把字符串s连接到当前字符串结尾
* `string& append(const char *s, int n);`                 //把字符串s的前n个字符连接到当前字符串结尾
* `string& append(const string &s);`                           //同operator+=(const string& str)
* `string& append(const string &s, int pos, int n);`//字符串s中从pos开始的n个字符连接到字符串结尾
*/
void test03() {
	//+=重构操作运算符
	std::string str1 = "我";
	str1 += "爱玩游戏";
	std::cout << str1 << std::endl;
	str1 += ':';
	std::cout << str1 << std::endl;
	std::string str2 = "CSGO:";
	str1 += str2;
	std::cout << str2 << std::endl;
	//append函数
	std::string str3 = "I";
	str3.append(" love");
	str3.append("you, and me", 4);
	std::string str4 = " waiting for you";
	str3.append(str4);
	str3.append(str4, 8, 16);
	std::cout << str3 << std::endl;
}