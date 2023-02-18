#include<iostream>
#include<set>

//��ӡ��������
void printSet(std::set<int>& s) {
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

}

void test72() {
	std::set<int> s;
	//insert��������
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	printSet(s);
	//��������
	std::set<int> s2(s);
	printSet(s2);
	//��ֵ
	std::set<int> s3;
	s3 = s2;
	printSet(s3);
}