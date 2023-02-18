#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>//随机数
class myPrint2
{
public:
	void operator()(int val)
	{
		std::cout << val << " ";
	}
};
//洗牌 打乱顺序
void test32() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//输出数据
	std::for_each(v.begin(), v.end(), myPrint2());
	std::cout << std::endl;
	std::srand((unsigned int)time(NULL));//保证每次随机数不同
	//打乱顺序
	std::random_shuffle(v.begin(), v.end());
	std::for_each(v.begin(), v.end(), myPrint2());
	std::cout << std::endl;
}