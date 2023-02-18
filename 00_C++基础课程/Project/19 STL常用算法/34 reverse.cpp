#include<iostream>
#include<vector>
#include<algorithm>
//打印数据规则
class MyPrint4 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

void test34() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	std::cout << "反转前" << std::endl;
	std::for_each(v.begin(), v.end(), MyPrint4());
	std::cout << std::endl;
	std::cout << "反转后" << std::endl;
	std::reverse(v.begin(), v.end());
	std::for_each(v.begin(), v.end(), MyPrint4());
	std::cout << std::endl;
}