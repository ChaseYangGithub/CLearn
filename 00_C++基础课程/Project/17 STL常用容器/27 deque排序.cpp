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
	//插入数据
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque7(d);
	//排序 默认规则从小到大 
	//对于支持随机访问的迭代器的容器都可以使用sort算法排序
	sort(d.begin(), d.end());
	printDeque7(d);
}