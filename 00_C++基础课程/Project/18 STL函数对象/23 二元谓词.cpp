#include<iostream>
#include<vector>
#include<algorithm>
//��ӡ����
void printData(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
//��Ԫν��
class MyCompare {
public:
	bool operator()(int num1, int num2) {
		return num1 > num2;
	}
};
void test23() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(21);
	v.push_back(16);
	v.push_back(51);
	//Ĭ�ϴ�С��������
	sort(v.begin(), v.end());
	printData(v);
	//ʹ�ú�������ı��㷨���ԣ������С����
	sort(v.begin(), v.end(), MyCompare());
	printData(v);
}