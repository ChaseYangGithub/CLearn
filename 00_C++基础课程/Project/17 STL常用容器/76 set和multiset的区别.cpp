#include<iostream>
#include<set>

void test76() {
	std::set<int> s;
	std::pair<std::set<int>::iterator, bool> ret = s.insert(10);//插入数据返回数据类型为pair<数据类型iterator ，bool> bool表明成功失败。看定义
	if (ret.second) {//ret.second表示返回数据ret接收的第二个数据
		std::cout << "第一次插入成功" << std::endl;
	}
	else {
		std::cout << "第一次插入失败" << std::endl;
	}
	ret = s.insert(10);
	if (ret.second) {
		std::cout << "第2次插入成功" << std::endl;
	}
	else {
		std::cout << "第2次插入失败" << std::endl;
	}
	//multiset
	std::multiset<int> m;
	m.insert(10);
	m.insert(10);
	for (std::multiset<int>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}