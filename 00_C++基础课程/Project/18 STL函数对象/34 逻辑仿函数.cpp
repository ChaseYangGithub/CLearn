#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
//�������
void printMes(std::vector<bool>& v) {
	for (std::vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


void test34() {
	std::vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	printMes(v);
	//�߼��� vת�Ƶ�v2��ִ���߼�������
	std::vector<bool> v2;
	v2.resize(v.size());//���ÿռ�Ϊԭʼ�ռ��С
	//ת�ƿ�ʼλ�� ����λ�� Ŀ�꿪ʼλ�� ִ�в���
	std::transform(v.begin(), v.end(), v2.begin(), std::logical_not<bool>());
	printMes(v2);
}