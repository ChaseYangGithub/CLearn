#include<iostream>
/*
* `string& insert(int pos, const char* s);  `                //�����ַ���
* `string& insert(int pos, const string& str); `        //�����ַ���
* `string& insert(int pos, int n, char c);`                //��ָ��λ�ò���n���ַ�c
* `string& erase(int pos, int n = npos);`                    //ɾ����Pos��ʼ��n���ַ� 
*/

void test07() {
	std::string str = "I";
	str.insert(1," love");
	std::cout << str << std::endl;

	str.erase(1, 3);//���±�Ϊ1��ʼɾ������Ϊ3���ַ���
	std::cout << str <<std::endl;
}