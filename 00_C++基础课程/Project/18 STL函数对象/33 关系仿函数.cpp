#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
//��ϵ�º��� ʵ�ֹ�ϵ�Ա�

//�ȽϷº���
class MyCompare2 {
public:
	bool operator()(int val, int val2) {
		return val > val2;
	}
};
//�������
void printMess(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test33() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	printMess(v);
	//�Լ�ʵ�ַº���
	sort(v.begin(), v.end(), MyCompare2());
	//STL�ڽ��º��� ���ڷº���
	sort(v.begin(), v.end(), std::greater<int>());
	printMess(v);
}