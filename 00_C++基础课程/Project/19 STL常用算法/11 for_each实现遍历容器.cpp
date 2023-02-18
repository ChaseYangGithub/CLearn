#include<iostream>
#include<algorithm>
#include<vector>
//普通函数
void print01(int val) {
	std::cout << val << " ";
}
//函数对象
class Print02 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

//for_each实现遍历容器
void test11() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(2*i);
	}
	//遍历算法 函数方式
	std::for_each(v.begin(), v.end(), print01);
	std::cout << std::endl;
	//遍历算法 函数对象方式
	std::for_each(v.begin(), v.end(), Print02());
	std::cout << std::endl;
}