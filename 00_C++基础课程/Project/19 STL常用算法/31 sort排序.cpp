#include<iostream>
#include<algorithm>
#include<vector>

//�����Ϣ
void myPrint(int val) {
	std::cout << val << " ";
}

void test31() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	// sortĬ�ϴ�С��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	std::cout << std::endl;

	//�Ӵ�С����
	sort(v.begin(), v.end(), std::greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	std::cout << std::endl;
}