#include<iostream>
#include<vector>


void printVector3(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test14() {
	std::vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector3(v1);
	if (v1.empty()) {
		std::cout << "v1Ϊ��" << std::endl;
	}
	else {
		std::cout << "v1��Ϊ��" << std::endl
			<< "v1������=" << v1.capacity() << std::endl
			<< "v1�Ĵ�С=" << v1.size() << std::endl;
	}
	//resize����ָ����С,��������10�������
	v1.resize(15, 10);
	printVector3(v1);
	//resize ����С��ɾ����������
	v1.resize(5);
	printVector3(v1);
}