#include<iostream>
/*
* `string& operator+=(const char* str);`                   //����+=������
* `string& operator+=(const char c);`                         //����+=������
* `string& operator+=(const string& str);`                //����+=������
* `string& append(const char *s); `                               //���ַ���s���ӵ���ǰ�ַ�����β
* `string& append(const char *s, int n);`                 //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
* `string& append(const string &s);`                           //ͬoperator+=(const string& str)
* `string& append(const string &s, int pos, int n);`//�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
*/
void test03() {
	//+=�ع����������
	std::string str1 = "��";
	str1 += "������Ϸ";
	std::cout << str1 << std::endl;
	str1 += ':';
	std::cout << str1 << std::endl;
	std::string str2 = "CSGO:";
	str1 += str2;
	std::cout << str2 << std::endl;
	//append����
	std::string str3 = "I";
	str3.append(" love");
	str3.append("you, and me", 4);
	std::string str4 = " waiting for you";
	str3.append(str4);
	str3.append(str4, 8, 16);
	std::cout << str3 << std::endl;
}