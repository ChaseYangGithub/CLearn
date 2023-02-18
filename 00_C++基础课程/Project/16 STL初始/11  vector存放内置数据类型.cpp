#include<iostream>
#include<vector>
#include<algorithm>//��׼�㷨

void myPrint(int val) {
	std::cout << val << std::endl;
}

void test11() {
	//����vector�������󣬲�ͨ��ģ�����ָ�������д洢����������
	std::vector<int> v;
	//�������д������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	//ÿһ�����������Լ��ĵ����������������������������е�Ԫ��
	//v.begin()���ص����������������ָ�������е�һ������
	//v.end()���ص����������������ָ������Ԫ�ص����һ��Ԫ�ص���һ��λ��
	//vector<int>::iterator �õ�vector<int>���������ĵ���������
	std::vector<int>::iterator pBegin = v.begin();
	std::vector<int>::iterator pEnd = v.end();

	//��һ�ֱ�����ʽ��
	while (pBegin != pEnd) {
		std::cout << *pBegin << std::endl;
		pBegin++;
	}
	//�ڶ��ֱ�����ʽ��
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	//�����ֱ�����ʽ��
	//ʹ��STL�ṩ��׼�����㷨  ͷ�ļ� algorithm
	for_each(v.begin(), v.end(), myPrint);
}