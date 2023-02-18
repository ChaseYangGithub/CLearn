#include<iostream>
#include<vector>
#include<numeric>

void test51() {
	std::vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	//指定值在指定空间的总数和指定值的和 值为 a-b的sum值+val
	int total = std::accumulate(v.begin(), v.end(),1);
	std::cout << total << std::endl;
}