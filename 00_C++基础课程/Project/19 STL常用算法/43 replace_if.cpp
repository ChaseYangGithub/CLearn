#include<iostream>
#include<vector>
#include<algorithm>
//打印容器
class MyPrint7 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};
//替换条件
class Gate {
public:
	bool operator()(int val) {
		return val > 10;
	}
};
void test43() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	v.push_back(15);
	v.push_back(16);
	v.push_back(14);
	std::for_each(v.begin(), v.end(), MyPrint7());
	std::cout << std::endl;
	//替换大于10的 为1000
	std::replace_if(v.begin(), v.end(), Gate(), 1000);
	std::for_each(v.begin(), v.end(), MyPrint7());

}