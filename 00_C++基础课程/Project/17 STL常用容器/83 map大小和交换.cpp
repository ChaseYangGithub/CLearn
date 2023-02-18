#include<iostream>
#include<map>
//打印容器数据
void printMap2(std::map<int, int>& m) {
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << " " << it->second << " ";
	}
	std::cout << std::endl;
}
void test83() {
	std::map<int, int> m;
	m.insert(std::pair<int, int>(1, 10));
	m.insert(std::pair<int, int>(11, 110));
	m.insert(std::pair<int, int>(111, 1110));
	m.insert(std::pair<int, int>(1111, 11110));
	printMap2(m);
	//判断是否为空
	if (m.empty()) {
		std::cout << "为空" << std::endl;
	}
	else {
		std::cout << "空间大小为：" << m.size() << std::endl;
	}
	std::map<int, int> m2;
	m2.insert(std::pair<int, int>(2, 20));
	m2.insert(std::pair<int, int>(22, 220));
	m2.insert(std::pair<int, int>(222, 2220));
	m2.insert(std::pair<int, int>(2222, 22220));
	printMap2(m2);
	m.swap(m2);
	printMap2(m);
	printMap2(m2);
}