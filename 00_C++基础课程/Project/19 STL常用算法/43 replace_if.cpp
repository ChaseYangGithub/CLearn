#include<iostream>
#include<vector>
#include<algorithm>
//��ӡ����
class MyPrint7 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};
//�滻����
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
	//�滻����10�� Ϊ1000
	std::replace_if(v.begin(), v.end(), Gate(), 1000);
	std::for_each(v.begin(), v.end(), MyPrint7());

}