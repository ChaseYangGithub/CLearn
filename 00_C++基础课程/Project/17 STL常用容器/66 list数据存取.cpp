#include<iostream>
#include<list>
//��ֵ���
void printList6(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test66() {
	std::list<int> l;
	l.push_back(10);
	l.push_back(12);
	l.push_back(13);
	l.push_back(14);
	//std::cout << l.at(1) << std::endl;//��֧��at����
	//std::cout << l.[1] << std::endl;//��֧��[]����
	std::cout << "��һ��Ԫ��Ϊ"<< l.front() << std::endl;
	std::cout << "��һ�и�Ԫ��Ϊ:" << l.back() << std::endl;
	//list������˫�����������֧���������
	std::list<int>::iterator it = l.begin();
	//it=it+1;//��֪֧����Ծ���ʣ�
	it++;
}