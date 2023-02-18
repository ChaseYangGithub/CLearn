#include<iostream>
#include<vector>
#include<algorithm>
//打印容器
class MyPrint5 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

void test41(){
	std::vector<int> v;
	v.push_back(10);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	std::for_each(v.begin(), v.end(), MyPrint5());
	std::cout << std::endl;
	std::vector<int> des;
	//重置大小为原有容器大小
	des.resize(v.size());
	//赋值容器
	std::copy(v.begin(), v.end(), des.begin());
	std::for_each(des.begin(), des.end(), MyPrint5());

}