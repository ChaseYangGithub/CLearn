#include<iostream>
#include<deque>

void printDeque(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test21() {
	std::deque<int> d1;//�޲ι��캯��
	for (int i = 0; i < 10; i++) {//����¼��
		d1.push_back(i);
	}
	printDeque(d1);
	//���� ����֮�������
	std::deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);
	//����n��ָ������
	std::deque<int> d3(10, 21);
	printDeque(d3);
	//�������캯��
	std::deque<int> d4(d3);
	printDeque(d4);
}