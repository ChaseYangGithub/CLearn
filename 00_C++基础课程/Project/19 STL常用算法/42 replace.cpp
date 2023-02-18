#include<iostream>
#include<vector>
#include<algorithm>
//打印容器
class MyPrint6 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

void test42() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	v.push_back(16);
	v.push_back(14);
	std::for_each(v.begin(), v.end(), MyPrint6());
	std::cout << std::endl;
	//替换所有的14 为41
	std::replace(v.begin(), v.end(), 14, 41);
	std::for_each(v.begin(), v.end(), MyPrint6());

}