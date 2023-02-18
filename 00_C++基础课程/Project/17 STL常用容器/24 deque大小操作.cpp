#include<iostream>
#include<deque>

void printDeque4(const std::deque<int>& d) {
	for ( std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test24() {
	std::deque<int> d;
	for (int i = 0; i < 5; i++) {
		d.push_back(i);
	}
	printDeque4(d);
	//判断容器是否为空
	if (d.empty()) {
		std::cout << "d为空" << std::endl;
	}
	else {
		//统计大小
		std::cout <<"大小为："<< d.size() << std::endl;
	}
	//重新制定大小-大
	d.resize(10,1);
	printDeque4(d);

	//重新指定大小-小
	d.resize(5);
	printDeque4(d);

}