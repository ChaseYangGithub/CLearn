#include<iostream>
#include<vector>
#include<algorithm>
//��ӡ����
class MyPrint5 {
public:
	void operator()(int val) {
		std::cout << val << " ";
	}
};

void test41(){
	std::vector<int> v;
	v.push_back(10);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
	std::for_each(v.begin(), v.end(), MyPrint5());
	std::cout << std::endl;
	std::vector<int> des;
	//���ô�СΪԭ��������С
	des.resize(v.size());
	//��ֵ����
	std::copy(v.begin(), v.end(), des.begin());
	std::for_each(des.begin(), des.end(), MyPrint5());

}