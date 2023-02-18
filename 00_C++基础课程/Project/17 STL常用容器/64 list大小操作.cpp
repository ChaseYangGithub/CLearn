#include<iostream>
#include<list>
//���list
void printList3(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test64() {
	std::list<int> l;
	l.push_back(10);
	l.push_back(11);
	l.push_back(12);
	l.push_back(13);
	//�ж��Ƿ�Ϊ��
	if (l.empty()) {
		std::cout << "listΪ��" << std::endl;
	}
	else {
		std::cout << "l��Ϊ��" << std::endl;
		std::cout << "l�Ĵ�СΪ��" << l.size() << std::endl;
	}
	//����ָ����С
	l.resize(10);//Ĭ������intֵΪ0
	printList3(l);
	l.resize(2);
	printList3(l);
}