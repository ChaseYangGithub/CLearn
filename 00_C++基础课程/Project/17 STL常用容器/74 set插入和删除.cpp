#include<iostream>
#include<set>
void printSet3(std::set<int>& s) {
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
 }
//set�����ɾ��
void test74() {
	std::set<int> s;
	//����
	s.insert(1);
	s.insert(12);
	s.insert(13);
	s.insert(14);
	printSet3(s);
	//ɾ��ָ��λ������
	s.erase(s.begin());
	printSet3(s);
	//ɾ��ָ����������
	s.erase(s.begin(), s.end());
	//���
	s.clear();
	printSet3(s);
}