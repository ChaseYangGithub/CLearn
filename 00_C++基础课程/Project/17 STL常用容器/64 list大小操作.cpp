#include<iostream>
#include<list>
//输出list
void printList3(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test64() {
	std::list<int> l;
	l.push_back(10);
	l.push_back(11);
	l.push_back(12);
	l.push_back(13);
	//判断是否为空
	if (l.empty()) {
		std::cout << "list为空" << std::endl;
	}
	else {
		std::cout << "l不为空" << std::endl;
		std::cout << "l的大小为：" << l.size() << std::endl;
	}
	//重新指定大小
	l.resize(10);//默认扩充int值为0
	printList3(l);
	l.resize(2);
	printList3(l);
}