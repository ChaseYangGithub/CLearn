#include<iostream>
#include<set>

void test75() {
	std::set<int> s;
	//����
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	//����
	std::set<int>::iterator pos = s.find(30);
	if (pos != s.end()) {
		std::cout << "�ҵ���Ԫ��" << *pos << std::endl;
	}
	else {
		std::cout << "δ�ҵ�Ԫ��" << std::endl;
	}
	//ͳ��
	int num =s.count(30);//����set����ͳ�ƽ��Ҫô��0Ҫô��1
	std::cout << "num=" << num << std::endl;
}
