#include<iostream>
#include<vector>
#include<algorithm>

class MyPrint12 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

void test63() {
	std::vector<int> v;
	std::vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		v2.push_back(2 * i);
	}
	std::for_each(v.begin(), v.end(), MyPrint12());
	std::cout << std::endl;
	std::for_each(v2.begin(), v2.end(), MyPrint12());
	std::cout << std::endl;
	std::vector<int> target;
	//���ٿռ�Ϊ���߽ϴ�ֵ
	target.resize(std::max(v.size() , v2.size()));
	//�󲢼�  1�ռ� 2�ռ� 3��ſ�ʼλ��	 ����Ŀ�����������һ��Ԫ�صĵ�������ַ
	std::vector<int>::iterator it = std::set_difference(v.begin(), v.end(), v2.begin(), v2.end(), target.begin());
	std::for_each(target.begin(), it, MyPrint12());
	std::cout << std::endl;
}