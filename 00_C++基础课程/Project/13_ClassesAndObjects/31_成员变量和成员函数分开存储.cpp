#include<iostream>
using namespace std;
//成员变量和成员函数分开存储

//地图类
class Graph {
	int g_a;//非静态成员，属于类的对象，存储在类中
	static int g_b;//静态成员，不属于类成员 不存储在类中
	void func() {};	//非静态成员函数 不属于类的对象，静态函数也是
};
int Graph::g_b = 1;




//成员变量和成员函数
void useSize() {
	Graph g;
	//空对象占用大小为1
	cout << "大小:" << sizeof(g) << endl;
}