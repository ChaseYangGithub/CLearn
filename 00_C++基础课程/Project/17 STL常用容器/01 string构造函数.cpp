#include<iostream>
//#include<string>//string����

//string�������
void test01() {
	std::string s1;//�������ַ����������޲ι��캯��
	std::cout << "str1=" << s1 << std::endl;

	const char* str = "hello world";
	std::string s2(str);//��c_stringת����string
	std::cout << "str2=" << s2 << std::endl;
	
	std::string s3(s2);//�������캯��
	std::cout << "str3=" << s3 << std::endl;

	std::string s4(10, 'a');////ʹ��n���ַ�c��ʼ��
	std::cout << "str4=" << s4 << std::endl;

}