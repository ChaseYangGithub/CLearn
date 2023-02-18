#include<iostream>
#include<vector>

void printVector6(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test17() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	printVector6(v);

	std::vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v2.push_back(10 - i);
	}
	printVector6(v2);
	//��������
	std::cout << "������" << std::endl;
	v.swap(v2);
	printVector6(v);
	printVector6(v2);

	v.clear();
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}

	std::cout << "v������Ϊ��" << v.capacity() << std::endl
		<< "v�Ĵ�СΪ��" << v.size() << std::endl;
	v.resize(3);//����ָ����С
	std::cout << "v������Ϊ��" << v.capacity() << std::endl
		<< "v�Ĵ�СΪ��" << v.size() << std::endl;

	//�����ڴ�
	std::vector<int>(v).swap(v); //������������Ȼ��ʹ��swap���������ռ�
	std::cout << "v������Ϊ��" << v.capacity() << std::endl
	 << "v�Ĵ�СΪ��" << v.size() << std::endl;
}
