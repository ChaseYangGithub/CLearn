#include<iostream>
#include<map>

void test85() {
	std::map<int, int> m;
	m.insert(std::pair<int, int>(1, 1));
	m.insert(std::pair<int, int>(2, 2));
	m.insert(std::pair<int, int>(3, 3));
	//����
	std::map<int, int>::iterator pos = m.find(2);
	//û��end���ҵ�
	if (pos != m.end()) {
		std::cout << "�ҵ���Ԫ��key=" << pos->first << " value=" << pos->second << std::endl;
	}
	else {
		std::cout << "Ԫ��δ�ҵ�" << std::endl;
	}
	//ͳ��
	int num = m.count(3);
	std::cout << "ͳ������3 �У�" << num << std::endl;
}