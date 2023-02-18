#include<iostream>
#include<vector>
#include<algorithm>

class Transform {
public:
	int operator()(int val) {
		return val;
	}
};

class MyPrint {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};
//���ñ����㷨 ����transform
void test12() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	std::vector<int> v2;//Ŀ������
	v2.resize(v.size());
	//����
	std::transform(v.begin(), v.end(), v2.begin(), Transform());
	//���
	std::for_each(v2.begin(), v2.end(), MyPrint());
}