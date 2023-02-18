#include<iostream>
#include<vector>
#include<algorithm>
//merge 两个容器合并到一起，并存储到另一个容器中
//merge合并的两个容器必须的有序序列

//打印数据
class myPrint3 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

void test33() {
	std::vector<int> v1;
	std::vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	std::vector<int> vtarget;
	//目标容器需要提前开辟空间
	vtarget.resize(v1.size() + v2.size());
	//合并，需要有两个有序序列
	std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	std::for_each(vtarget.begin(), vtarget.end(), myPrint3());
	std::cout << std::endl;
}