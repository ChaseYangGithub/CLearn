#include<iostream>
#include<deque>
#include<algorithm>
void printDeque7(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test27() {
	std::deque<int> d;
	//��������
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque7(d);
	//���� Ĭ�Ϲ����С���� 
	//����֧��������ʵĵ�����������������ʹ��sort�㷨����
	sort(d.begin(), d.end());
	printDeque7(d);
}