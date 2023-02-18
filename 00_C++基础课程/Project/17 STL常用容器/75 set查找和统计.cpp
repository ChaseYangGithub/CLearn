#include<iostream>
#include<set>

void test75() {
	std::set<int> s;
	//插入
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	//查找
	std::set<int>::iterator pos = s.find(30);
	if (pos != s.end()) {
		std::cout << "找到了元素" << *pos << std::endl;
	}
	else {
		std::cout << "未找到元素" << std::endl;
	}
	//统计
	int num =s.count(30);//对于set而言统计结果要么是0要么是1
	std::cout << "num=" << num << std::endl;
}
