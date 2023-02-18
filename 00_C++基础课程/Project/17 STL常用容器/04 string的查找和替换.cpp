#include<iostream>
/*
* `int find(const string& str, int pos = 0) const;`              //����str��һ�γ���λ��,��pos��ʼ����
* `int find(const char* s, int pos = 0) const; `                     //����s��һ�γ���λ��,��pos��ʼ����
* `int find(const char* s, int pos, int n) const; `               //��posλ�ò���s��ǰn���ַ���һ��λ��
* `int find(const char c, int pos = 0) const; `                       //�����ַ�c��һ�γ���λ��
* `int rfind(const string& str, int pos = npos) const;`      //����str���һ��λ��,��pos��ʼ����
* `int rfind(const char* s, int pos = npos) const;`              //����s���һ�γ���λ��,��pos��ʼ����
* `int rfind(const char* s, int pos, int n) const;`              //��pos����s��ǰn���ַ����һ��λ��
* `int rfind(const char c, int pos = 0) const;  `                      //�����ַ�c���һ�γ���λ��
* `string& replace(int pos, int n, const string& str); `       //�滻��pos��ʼn���ַ�Ϊ�ַ���str
* `string& replace(int pos, int n,const char* s); `                 //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
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