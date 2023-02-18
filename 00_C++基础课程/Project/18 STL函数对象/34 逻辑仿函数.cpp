#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
//输出数据
void printMes(std::vector<bool>& v) {
	for (std::vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


void test34() {
	std::vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	printMes(v);
	//逻辑非 v转移到v2并执行逻辑非运算
	std::vector<bool> v2;
	v2.resize(v.size());//设置空间为原始空间大小
	//转移开始位置 结束位置 目标开始位置 执行操作
	std::transform(v.begin(), v.end(), v2.begin(), std::logical_not<bool>());
	printMes(v2);
}