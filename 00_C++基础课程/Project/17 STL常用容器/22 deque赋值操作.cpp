#include<iostream>
#include<deque>

//打印deque数据
void printDeque2(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test22() {
	std::deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	printDeque2(d);
	//操作符重载方式
	std::deque<int> d2;
	d2 = d;
	printDeque2(d2);
	//assign方式拷贝区间数据
	std::deque<int> d3;
	d3.assign(d.begin(), d.end());
	printDeque2(d3);
	//assign将n个指定数据赋值
	std::deque<int> d4;
	d4.assign(10, 100);
	printDeque2(d4);
}