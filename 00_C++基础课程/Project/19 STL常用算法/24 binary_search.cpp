#include<iostream>
#include<vector>
#include<algorithm>
//����ָ��Ԫ�������Ƿ����
void test24() {
	std::vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}
	//���ֲ��� ������������Ч�ʺܸ�
	bool ret = std::binary_search(v.begin(), v.end(),1);
	if (ret) {
		std::cout << "�ҵ���" << std::endl;
	}
	else {
		std::cout << "δ�ҵ�" << std::endl;
	}
}