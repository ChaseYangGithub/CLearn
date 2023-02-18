#include<iostream>
#include<vector>
#include<algorithm>
//查找相邻重复元素
void test23() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(11);
	v.push_back(13);
	v.push_back(15);
	v.push_back(13);
	v.push_back(13);
	v.push_back(16);
	//查找相邻重复元素	
	std::vector<int>::iterator it = std::adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		std::cout << "找不到" << std::endl;
	}
	else {
		std::cout << "找到相邻重复元素:" << *it << std::endl;
	}
}