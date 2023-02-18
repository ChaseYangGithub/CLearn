#include<iostream>
#include<vector>

void test18() {
	std::vector<int> v;
	//预留空间
	v.reserve(10000);
	int num = 0;//统计开辟次数
	int* p = NULL;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	std::cout << num << std::endl;
}