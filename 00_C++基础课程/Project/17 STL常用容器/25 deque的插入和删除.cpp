#include<iostream>
#include<deque>

void printDeque5(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test25() {
	std::deque<int> d;
	//β��
	d.push_back(10);
	d.push_back(20);
	//ͷ��
	d.push_front(100);
	d.push_front(200);
	printDeque5(d);
	//βɾ
	d.pop_back();
	//ͷɾ
	d.pop_front();
	printDeque5(d);
	//ָ��λ�ò���
	d.insert(d.begin(), 1000);
	printDeque5(d);
	//ָ��λ�ò���n��ָ������
	d.insert(d.begin(), 2, 1111);
	printDeque5(d);
	//��ָ��λ�ò���ĳ�����������
	d.insert(d.begin(), d.begin(), d.end());
	printDeque5(d);
	//ɾ��ָ��λ������
	d.erase(d.begin());
	printDeque5(d);
	//��ո�����
	d.clear();
	printDeque5(d);


}