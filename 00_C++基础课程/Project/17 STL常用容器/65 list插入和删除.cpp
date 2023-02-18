#include<iostream>
#include<list>
//数据输出
void printList5(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test65() {
	std::list<int> l;
	//尾插法
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	//头插法
	l.push_front(10);
	l.push_front(20);
	l.push_front(30);
	l.push_front(40);
	printList5(l);
	//尾删法
	l.pop_back();
	printList5(l);
	//头删
	l.pop_front();
	printList5(l);
	//插入 insert插入数据
	std::list<int>::iterator it = l.begin();
	l.insert(++it, 1000);
	printList5(l);
	//删除
	it = l.begin();
	l.erase(++it);
	printList5(l);
	//移除 指定匹配的所有数据
	l.push_back(10000);
	l.push_back(10000);
	l.push_back(10000);
	l.push_back(10000);
	printList5(l);
	l.remove(10000);
	printList5(l);
	//清空数据
	l.clear();
	printList5(l);

}