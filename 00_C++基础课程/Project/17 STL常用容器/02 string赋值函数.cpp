#include<iostream>

void test02() {
	//��������ط�ʽ
	//const char *��ʽ
	std::string str1;
	str1 = "hello world";
	std::cout << str1 << std::endl;
	//���ַ���s��ֵ����ǰ���ַ���
	std::string str2;
	str2 = str1;
	std::cout << str2 << std::endl;
	//�ַ���ֵ����ǰ���ַ���
	std::string str3;
	str3 = '2';
	std::cout << str3 << std::endl;
	//assign������ʽ
	//���ַ���s��ֵ����ֵ����ǰ���ַ���
	std::string str4;
	str4.assign("hello C++");
	std::cout<<str4<<std::endl;
	//���ַ���s��ǰn���ַ���ֵ����ǰ�ַ���
	std::string str5;
	str5.assign("123456", 5);
	std::cout << str5 << std::endl;
	//���ַ���s��ֵ����ǰ�ַ���
	std::string str6;
	str6.assign(str5);
	std::cout << str6 << std::endl;
	//��n���ַ�c��ֵ����ǰ�ַ���
	std::string str7;
	str7.assign(5, 'q');
	std::cout << str7 << std::endl;
}