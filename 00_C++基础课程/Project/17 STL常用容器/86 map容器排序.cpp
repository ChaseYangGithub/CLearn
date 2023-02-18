#include<iostream>
#include<map>

class MyCompare {
public:
	//仿函数。排序规则 递减
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};
void test86() {
	//默认从小到大排序
	std::map<int, int, MyCompare> m;
	m.insert(std::make_pair(1, 10));
	m.insert(std::make_pair(2, 20));
	m.insert(std::make_pair(3, 30));
	m.insert(std::make_pair(4, 40));
	//输出
	for (std::map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << "Key::" << it->first << " Value::" << it->second << std::endl;
	}
}