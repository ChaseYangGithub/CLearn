#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
//关系仿函数 实现关系对比

//比较仿函数
class MyCompare2 {
public:
	bool operator()(int val, int val2) {
		return val > val2;
	}
};
//数据输出
void printMess(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test33() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	printMess(v);
	//自己实现仿函数
	sort(v.begin(), v.end(), MyCompare2());
	//STL内建仿函数 大于仿函数
	sort(v.begin(), v.end(), std::greater<int>());
	printMess(v);
}