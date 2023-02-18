#include<iostream>
#include<list>
//赋值输出
void printList6(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test66() {
	std::list<int> l;
	l.push_back(10);
	l.push_back(12);
	l.push_back(13);
	l.push_back(14);
	//std::cout << l.at(1) << std::endl;//不支持at访问
	//std::cout << l.[1] << std::endl;//不支持[]访问
	std::cout << "第一个元素为"<< l.front() << std::endl;
	std::cout << "第一行个元素为:" << l.back() << std::endl;
	//list容器是双向迭代器，不支持随机访问
	std::list<int>::iterator it = l.begin();
	//it=it+1;//不知支持跳跃访问，
	it++;
}