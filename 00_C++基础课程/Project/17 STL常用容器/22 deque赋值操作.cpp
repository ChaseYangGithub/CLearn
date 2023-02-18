#include<iostream>
#include<deque>

//��ӡdeque����
void printDeque2(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test22() {
	std::deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	printDeque2(d);
	//���������ط�ʽ
	std::deque<int> d2;
	d2 = d;
	printDeque2(d2);
	//assign��ʽ������������
	std::deque<int> d3;
	d3.assign(d.begin(), d.end());
	printDeque2(d3);
	//assign��n��ָ�����ݸ�ֵ
	std::deque<int> d4;
	d4.assign(10, 100);
	printDeque2(d4);
}