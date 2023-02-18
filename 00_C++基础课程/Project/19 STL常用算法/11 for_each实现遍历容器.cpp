#include<iostream>
#include<algorithm>
#include<vector>
//��ͨ����
void print01(int val) {
	std::cout << val << " ";
}
//��������
class Print02 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

//for_eachʵ�ֱ�������
void test11() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(2*i);
	}
	//�����㷨 ������ʽ
	std::for_each(v.begin(), v.end(), print01);
	std::cout << std::endl;
	//�����㷨 ��������ʽ
	std::for_each(v.begin(), v.end(), Print02());
	std::cout << std::endl;
}