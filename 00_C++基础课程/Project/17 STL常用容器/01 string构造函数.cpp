#include<iostream>
//#include<string>//string容器

//string构造测试
void test01() {
	std::string s1;//创建空字符串，调用无参构造函数
	std::cout << "str1=" << s1 << std::endl;

	const char* str = "hello world";
	std::string s2(str);//将c_string转化成string
	std::cout << "str2=" << s2 << std::endl;
	
	std::string s3(s2);//拷贝构造函数
	std::cout << "str3=" << s3 << std::endl;

	std::string s4(10, 'a');////使用n个字符c初始化
	std::cout << "str4=" << s4 << std::endl;

}