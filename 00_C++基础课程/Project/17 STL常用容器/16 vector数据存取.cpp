#include<iostream>
#include<vector>

void test16() {
	std::vector<int> v;
	//��������
	for (int i = 0; i < 10; i++) {
		v.push_back(2 * i + 3);
	}
	//[]��ʽ�������
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	//at��ʽ�������
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "v��һ��Ԫ��Ϊ��" << v.front() << std::endl
		<< "v���һ��Ԫ��Ϊ��" << v.back() << std::endl;
}