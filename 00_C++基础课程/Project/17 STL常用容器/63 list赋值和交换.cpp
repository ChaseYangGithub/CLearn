#include<iostream>
#include<list>
//打印list数据
void printList2(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
//list赋值和交换
void test63() {
	std::list<int> l;
	//赋值
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	printList2(l);
	//赋值 重载=方式
	std::list<int> l2;
	l2 = l;
	printList2(l2);
	//赋值 区间赋值
	std::list<int> l3;
	l3.assign(l.begin(), l.end());
	printList2(l3);
	//赋值 指定数据重复
	std::list<int> l4;
	l4.assign(6, 21);
	printList2(l4);
	//交换l和l4
	std::cout << "交换l和l4" << std::endl;
	l.swap(l4);
	printList2(l);
	printList2(l4);
}