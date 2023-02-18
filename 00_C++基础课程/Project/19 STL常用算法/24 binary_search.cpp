#include<iostream>
#include<vector>
#include<algorithm>
//查找指定元素搜索是否存在
void test24() {
	std::vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}
	//二分查找 在有序序列中效率很高
	bool ret = std::binary_search(v.begin(), v.end(),1);
	if (ret) {
		std::cout << "找到了" << std::endl;
	}
	else {
		std::cout << "未找到" << std::endl;
	}
}