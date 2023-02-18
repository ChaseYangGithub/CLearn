#include<iostream>
#include<vector>

//�����������
void printVector4(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
//vector�����ɾ��
void test15() {
	std::vector<int> v;
	//β�巨
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector4(v);
	//β��
	v.pop_back();
	printVector4(v);
	//���� ������ָ���λ�ò���ָ������
	v.insert(v.begin(), 100);
	printVector4(v);
	//���� ������ָ���λ�ò��� n��ָ������
	v.insert(v.begin(), 2, 1000);
	printVector4(v);
	//ɾ��������ָ���Ԫ��
	v.erase(v.begin());
	printVector4(v);
	//���
	v.erase(v.begin(), v.end());//ɾ��������ָ�����������
	v.clear();//ɾ������������Ԫ��
	printVector4(v);
}