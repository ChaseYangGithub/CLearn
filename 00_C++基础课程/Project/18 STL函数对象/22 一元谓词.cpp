#include<iostream>
#include<vector>
#include<algorithm>//�㷨
//һԪν��
struct GreateFive {//�˴��ȼ��� class GreatFive Ȼ��public���غ���
	bool operator()(int val) {
		return val > 5;
	}
};

void test22() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	//�㷨��������������Ҫ�Ľ��     GivemeFive������������
	std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), GreateFive());
	//�жϲ������
	if (it == v.end()) {
		std::cout << "û�ҵ�" << std::endl;
	}
	else {
		std::cout << "�ҵ���" << *it << std::endl;
	}
}
