#ifndef ORDER
#define ORDER
#include<iostream>
#include<map>
//ԤԼ��
class Order {
public:
	//���캯��
	Order();
	//����ԤԼ��¼
	void UpdateOrder();
public:
	//��¼������  ��¼������  �������Ϣ
	std::map<int ,std::map<std::string, std::string>> data;
	//ԤԼ��¼������
	int size;
};
#endif