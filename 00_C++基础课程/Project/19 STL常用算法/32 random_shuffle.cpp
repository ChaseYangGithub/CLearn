#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>//�����
class myPrint2
{
public:
	void operator()(int val)
	{
		std::cout << val << " ";
	}
};
//ϴ�� ����˳��
void test32() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//�������
	std::for_each(v.begin(), v.end(), myPrint2());
	std::cout << std::endl;
	std::srand((unsigned int)time(NULL));//��֤ÿ���������ͬ
	//����˳��
	std::random_shuffle(v.begin(), v.end());
	std::for_each(v.begin(), v.end(), myPrint2());
	std::cout << std::endl;
}