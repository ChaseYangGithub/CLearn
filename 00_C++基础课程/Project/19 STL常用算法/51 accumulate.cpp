#include<iostream>
#include<vector>
#include<numeric>

void test51() {
	std::vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	//ָ��ֵ��ָ���ռ��������ָ��ֵ�ĺ� ֵΪ a-b��sumֵ+val
	int total = std::accumulate(v.begin(), v.end(),1);
	std::cout << total << std::endl;
}