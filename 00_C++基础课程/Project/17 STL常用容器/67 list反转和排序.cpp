#include<iostream>
#include<list>
//赋值输出
void printList7(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it <<" ";
	}
	std::cout << std::endl;
}
//比较
bool myCompare(int val1,int  val2) {
	//降序val1>val2
	return val1 > val2;
}
void test67() {
	std::list<int> l;
	l.push_back(1);
	l.push_back(12);
	l.push_back(13);
	l.push_back(14);
	printList7(l);
	//反转容器
	l.reverse();
	printList7(l);
	//排序
	//所有不支持随机访问迭代器的容器，不可以使用标准算法
	//不支持随机访问迭代器的算法，内部会提供对应的算法
	l.sort();//默认从小到大
	printList7(l);
	l.sort(myCompare);//指定规则 降序
	printList7(l);
}
