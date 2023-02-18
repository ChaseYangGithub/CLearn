#include<iostream>
#include<map>

void test85() {
	std::map<int, int> m;
	m.insert(std::pair<int, int>(1, 1));
	m.insert(std::pair<int, int>(2, 2));
	m.insert(std::pair<int, int>(3, 3));
	//查找
	std::map<int, int>::iterator pos = m.find(2);
	//没到end就找到
	if (pos != m.end()) {
		std::cout << "找到了元素key=" << pos->first << " value=" << pos->second << std::endl;
	}
	else {
		std::cout << "元素未找到" << std::endl;
	}
	//统计
	int num = m.count(3);
	std::cout << "统计数据3 有：" << num << std::endl;
}