#include<iostream>
#include<vector>
#include<algorithm>

class Transform {
public:
	int operator()(int val) {
		return val;
	}
};

class MyPrint {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};
//常用遍历算法 搬运transform
void test12() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	std::vector<int> v2;//目标容器
	v2.resize(v.size());
	//搬运
	std::transform(v.begin(), v.end(), v2.begin(), Transform());
	//输出
	std::for_each(v2.begin(), v2.end(), MyPrint());
}