#include<iostream>
#include<vector>
#include<algorithm>
//merge ���������ϲ���һ�𣬲��洢����һ��������
//merge�ϲ������������������������

//��ӡ����
class myPrint3 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

void test33() {
	std::vector<int> v1;
	std::vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	std::vector<int> vtarget;
	//Ŀ��������Ҫ��ǰ���ٿռ�
	vtarget.resize(v1.size() + v2.size());
	//�ϲ�����Ҫ��������������
	std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	std::for_each(vtarget.begin(), vtarget.end(), myPrint3());
	std::cout << std::endl;
}