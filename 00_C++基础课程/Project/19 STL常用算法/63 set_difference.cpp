#include<iostream>
#include<vector>
#include<algorithm>

class MyPrint12 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

void test63() {
	std::vector<int> v;
	std::vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		v2.push_back(2 * i);
	}
	std::for_each(v.begin(), v.end(), MyPrint12());
	std::cout << std::endl;
	std::for_each(v2.begin(), v2.end(), MyPrint12());
	std::cout << std::endl;
	std::vector<int> target;
	//开辟空间为两者较大值
	target.resize(std::max(v.size() , v2.size()));
	//求并集  1空间 2空间 3存放开始位置	 返回目标容器的最后一个元素的迭代器地址
	std::vector<int>::iterator it = std::set_difference(v.begin(), v.end(), v2.begin(), v2.end(), target.begin());
	std::for_each(target.begin(), it, MyPrint12());
	std::cout << std::endl;
}