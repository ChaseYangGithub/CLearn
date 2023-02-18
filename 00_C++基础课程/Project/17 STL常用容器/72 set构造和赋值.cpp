#include<iostream>
#include<set>

//打印容器数据
void printSet(std::set<int>& s) {
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

}

void test72() {
	std::set<int> s;
	//insert插入数据
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	printSet(s);
	//拷贝构造
	std::set<int> s2(s);
	printSet(s2);
	//赋值
	std::set<int> s3;
	s3 = s2;
	printSet(s3);
}