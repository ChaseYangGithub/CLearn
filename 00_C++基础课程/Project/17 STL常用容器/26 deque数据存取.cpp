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
	//重载[]方式读取数据
	for (int i = 0; i < d.size(); i++) {
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;
	//at方式读取数据
	for (int i = 0; i < d.size(); i++) {
		std::cout << d.at(i) << " ";
	}
	std::cout << std::endl;
	//输出第一个数据
	std::cout << d.front()<< std::endl;
	//输出最后一个数据
	std::cout << d.back() << std::endl;
}