#include<iostream>
#include<vector>

void test18() {
	std::vector<int> v;
	//Ԥ���ռ�
	v.reserve(10000);
	int num = 0;//ͳ�ƿ��ٴ���
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