#include<iostream>
#include<vector>
#include<algorithm>


//打印数据
class myPrint8{
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

void test44() {
	std::vector<int> v1;
	std::vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	//交换前
	std::for_each(v1.begin(), v1.end(), myPrint8());
	std::cout << std::endl;
	std::for_each(v2.begin(), v2.end(), myPrint8());
	std::cout << std::endl;
	std::swap(v1, v2);
	//交换后
	std::for_each(v1.begin(), v1.end(), myPrint8());
	std::cout << std::endl;
	std::for_each(v2.begin(), v2.end(), myPrint8());
	std::cout << std::endl;
}