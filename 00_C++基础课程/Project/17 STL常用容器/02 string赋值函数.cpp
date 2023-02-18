#include<iostream>

void test02() {
	//运算符重载方式
	//const char *方式
	std::string str1;
	str1 = "hello world";
	std::cout << str1 << std::endl;
	//将字符串s赋值给当前的字符串
	std::string str2;
	str2 = str1;
	std::cout << str2 << std::endl;
	//字符赋值给当前的字符串
	std::string str3;
	str3 = '2';
	std::cout << str3 << std::endl;
	//assign函数方式
	//将字符串s赋值给赋值给当前的字符串
	std::string str4;
	str4.assign("hello C++");
	std::cout<<str4<<std::endl;
	//将字符串s的前n个字符赋值给当前字符串
	std::string str5;
	str5.assign("123456", 5);
	std::cout << str5 << std::endl;
	//将字符串s赋值给当前字符串
	std::string str6;
	str6.assign(str5);
	std::cout << str6 << std::endl;
	//用n个字符c赋值给当前字符串
	std::string str7;
	str7.assign(5, 'q');
	std::cout << str7 << std::endl;
}