#include<iostream>
#include<list>
//��ӡlist����
void printList2(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
//list��ֵ�ͽ���
void test63() {
	std::list<int> l;
	//��ֵ
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	printList2(l);
	//��ֵ ����=��ʽ
	std::list<int> l2;
	l2 = l;
	printList2(l2);
	//��ֵ ���丳ֵ
	std::list<int> l3;
	l3.assign(l.begin(), l.end());
	printList2(l3);
	//��ֵ ָ�������ظ�
	std::list<int> l4;
	l4.assign(6, 21);
	printList2(l4);
	//����l��l4
	std::cout << "����l��l4" << std::endl;
	l.swap(l4);
	printList2(l);
	printList2(l4);
}