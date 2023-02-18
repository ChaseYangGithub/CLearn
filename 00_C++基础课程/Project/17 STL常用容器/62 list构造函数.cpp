#include<iostream>
#include<list>
//���list
void printList(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
//list���캯��
void test62() {
	std::list<int> l;
	//����¼��
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	printList(l);

	//���俽��
	std::list<int> l2(l.begin(), l.end());
	printList(l2);
	//��������
	std::list<int> l3(l2);
	printList(l3);
	//��ֵn��ָ��ֵ
	std::list<int> l4(5, 11);
	printList(l4);
}