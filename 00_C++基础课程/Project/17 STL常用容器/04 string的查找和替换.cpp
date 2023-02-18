#include<iostream>
/*
* `int find(const string& str, int pos = 0) const;`              //查找str第一次出现位置,从pos开始查找
* `int find(const char* s, int pos = 0) const; `                     //查找s第一次出现位置,从pos开始查找
* `int find(const char* s, int pos, int n) const; `               //从pos位置查找s的前n个字符第一次位置
* `int find(const char c, int pos = 0) const; `                       //查找字符c第一次出现位置
* `int rfind(const string& str, int pos = npos) const;`      //查找str最后一次位置,从pos开始查找
* `int rfind(const char* s, int pos = npos) const;`              //查找s最后一次出现位置,从pos开始查找
* `int rfind(const char* s, int pos, int n) const;`              //从pos查找s的前n个字符最后一次位置
* `int rfind(const char c, int pos = 0) const;  `                      //查找字符c最后一次出现位置
* `string& replace(int pos, int n, const string& str); `       //替换从pos开始n个字符为字符串str
* `string& replace(int pos, int n,const char* s); `                 //替换从pos开始的n个字符为字符串s
*/
void test04() {
	std::string str = "I love you,waiting for you,for you";
	int pos=str.find("you", 0);
	pos = str.find("I", 0);
	pos = str.find("love", 0,4);
	pos = str.find('o',0);
	std::string str2 = "ove";
	pos = str.rfind(str2, 18);
	pos = str.rfind("ove", 18);
	pos = str.rfind("ove", 18,2);
	pos = str.rfind('u', 18);
	std::cout << pos << std::endl;
	std::string str3 = "****";
	str.replace(2, 4, str3);
	str.replace(7, 3, "YOU");
	std::cout << str <<std::endl;
}