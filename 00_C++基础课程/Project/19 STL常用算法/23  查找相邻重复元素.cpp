#include<iostream>
#include<vector>
#include<algorithm>
//���������ظ�Ԫ��
void test23() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(11);
	v.push_back(13);
	v.push_back(15);
	v.push_back(13);
	v.push_back(13);
	v.push_back(16);
	//���������ظ�Ԫ��	
	std::vector<int>::iterator it = std::adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		std::cout << "�Ҳ���" << std::endl;
	}
	else {
		std::cout << "�ҵ������ظ�Ԫ��:" << *it << std::endl;
	}
}