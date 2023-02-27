#ifndef ORDER
#define ORDER
#include<iostream>
#include<map>
//预约类
class Order {
public:
	//构造函数
	Order();
	//更新预约记录
	void UpdateOrder();
public:
	//记录的容器  记录的条数  具体的信息
	std::map<int ,std::map<std::string, std::string>> data;
	//预约记录的条数
	int size;
};
#endif