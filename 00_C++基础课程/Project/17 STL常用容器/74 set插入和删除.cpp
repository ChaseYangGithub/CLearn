#include<iostream>
#include<set>
void printSet3(std::set<int>& s) {
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
 }
//set插入和删除
void test74() {
	std::set<int> s;
	//插入
	s.insert(1);
	s.insert(12);
	s.insert(13);
	s.insert(14);
	printSet3(s);
	//删除指定位置数据
	s.erase(s.begin());
	printSet3(s);
	//删除指定区间数据
	s.erase(s.begin(), s.end());
	//清空
	s.clear();
	printSet3(s);
}