#include<iostream>
#include<set>

void printSet2(std::set<int>& s) {
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test73() {
	std::set<int> s;
	s.insert(1);
	s.insert(11);
	s.insert(111);
	s.insert(1111);
	printSet2(s);
	//判断是否为空
	if (s.empty()) {
		std::cout << "set容器为空" << std::endl;
	}
	else {
		std::cout << "set容器不为空\n大小为：" << s.size() << std::endl;
	}
	std::set<int> s2;
	s2.insert(2);
	s2.insert(22);
	s2.insert(222);
	s2.insert(2222);
	printSet2(s2);
	s.swap(s2);//交换
	printSet2(s);
	printSet2(s2);
}