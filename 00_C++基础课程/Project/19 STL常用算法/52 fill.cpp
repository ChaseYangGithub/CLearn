#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
class MyPrint9 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};
void test52() {
	std::vector<int> v;
	v.resize(10);
	std::fill(v.begin(), v.end(), 100);
	std::for_each(v.begin(), v.end(), MyPrint9());
}