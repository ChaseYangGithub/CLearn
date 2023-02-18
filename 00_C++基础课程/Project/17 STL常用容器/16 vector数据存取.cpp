#include<iostream>
#include<vector>

void test16() {
	std::vector<int> v;
	//插入数据
	for (int i = 0; i < 10; i++) {
		v.push_back(2 * i + 3);
	}
	//[]方式输出数据
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	//at方式输出数据
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "v第一个元素为：" << v.front() << std::endl
		<< "v最后一个元素为：" << v.back() << std::endl;
}