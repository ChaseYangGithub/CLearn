#include<iostream>
#include<vector>
#include<algorithm>
//打印数据
void printData(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
//二元谓词
class MyCompare {
public:
	bool operator()(int num1, int num2) {
		return num1 > num2;
	}
};
void test23() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(21);
	v.push_back(16);
	v.push_back(51);
	//默认从小到大排序
	sort(v.begin(), v.end());
	printData(v);
	//使用函数对象改变算法策略，排序从小到大
	sort(v.begin(), v.end(), MyCompare());
	printData(v);
}