#include<iostream>
#include<deque>

void printDeque4(const std::deque<int>& d) {
	for ( std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test24() {
	std::deque<int> d;
	for (int i = 0; i < 5; i++) {
		d.push_back(i);
	}
	printDeque4(d);
	//�ж������Ƿ�Ϊ��
	if (d.empty()) {
		std::cout << "dΪ��" << std::endl;
	}
	else {
		//ͳ�ƴ�С
		std::cout <<"��СΪ��"<< d.size() << std::endl;
	}
	//�����ƶ���С-��
	d.resize(10,1);
	printDeque4(d);

	//����ָ����С-С
	d.resize(5);
	printDeque4(d);

}