#include<iostream>
#include<vector>

void test13() {
	std::vector<std::vector<int>> v;
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;
	std::vector<int> v4;
	std::vector<int> v5;

	for (int i = 0; i < 5; i++){//基础容器数据
		v1.push_back(i + 1);
		v2.push_back(i + 1);
		v3.push_back(i + 1);
		v4.push_back(i + 1);
		v5.push_back(i + 1);
	}
	//容器元素压入vector  v中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	for (std::vector<std::vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (std::vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			std::cout << *vit;
		}
		std::cout << std::endl;
	}

}