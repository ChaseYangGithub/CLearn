#include<iostream>
#include<list>
//�������
void printList5(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test65() {
	std::list<int> l;
	//β�巨
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	//ͷ�巨
	l.push_front(10);
	l.push_front(20);
	l.push_front(30);
	l.push_front(40);
	printList5(l);
	//βɾ��
	l.pop_back();
	printList5(l);
	//ͷɾ
	l.pop_front();
	printList5(l);
	//���� insert��������
	std::list<int>::iterator it = l.begin();
	l.insert(++it, 1000);
	printList5(l);
	//ɾ��
	it = l.begin();
	l.erase(++it);
	printList5(l);
	//�Ƴ� ָ��ƥ�����������
	l.push_back(10000);
	l.push_back(10000);
	l.push_back(10000);
	l.push_back(10000);
	printList5(l);
	l.remove(10000);
	printList5(l);
	//�������
	l.clear();
	printList5(l);

}