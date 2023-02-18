#include<iostream>
/*
* `string& insert(int pos, const char* s);  `                //插入字符串
* `string& insert(int pos, const string& str); `        //插入字符串
* `string& insert(int pos, int n, char c);`                //在指定位置插入n个字符c
* `string& erase(int pos, int n = npos);`                    //删除从Pos开始的n个字符 
*/

void test07() {
	std::string str = "I";
	str.insert(1," love");
	std::cout << str << std::endl;

	str.erase(1, 3);//从下标为1开始删除长度为3的字符串
	std::cout << str <<std::endl;
}