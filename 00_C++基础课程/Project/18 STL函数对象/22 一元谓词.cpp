#include<iostream>
#include<vector>
#include<algorithm>//算法
//一元谓词
struct GreateFive {//此处等价于 class GreatFive 然后public重载函数
	bool operator()(int val) {
		return val > 5;
	}
};

void test22() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	//算法，按条件查找想要的结果     GivemeFive匿名函数对象
	std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), GreateFive());
	//判断查找情况
	if (it == v.end()) {
		std::cout << "没找到" << std::endl;
	}
	else {
		std::cout << "找到：" << *it << std::endl;
	}
}
