#include<iostream>
#include<deque>

void printDeque5(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test25() {
	std::deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(100);
	d.push_front(200);
	printDeque5(d);
	//尾删
	d.pop_back();
	//头删
	d.pop_front();
	printDeque5(d);
	//指定位置插入
	d.insert(d.begin(), 1000);
	printDeque5(d);
	//指定位置插入n个指定数据
	d.insert(d.begin(), 2, 1111);
	printDeque5(d);
	//在指定位置插入某个区间的数据
	d.insert(d.begin(), d.begin(), d.end());
	printDeque5(d);
	//删除指定位置数据
	d.erase(d.begin());
	printDeque5(d);
	//清空该数据
	d.clear();
	printDeque5(d);


}