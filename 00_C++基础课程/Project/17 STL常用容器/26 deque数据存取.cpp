#include<iostream>
#include<deque>

void printDeque6(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test26() {
	std::deque<int> d;
	d.push_front(10);
	d.push_front(20);
	d.push_back(100);
	d.push_back(200);
	//����[]��ʽ��ȡ����
	for (int i = 0; i < d.size(); i++) {
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;
	//at��ʽ��ȡ����
	for (int i = 0; i < d.size(); i++) {
		std::cout << d.at(i) << " ";
	}
	std::cout << std::endl;
	//�����һ������
	std::cout << d.front()<< std::endl;
	//������һ������
	std::cout << d.back() << std::endl;
}