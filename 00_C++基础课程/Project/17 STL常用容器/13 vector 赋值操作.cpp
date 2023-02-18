#include<iostream>
#include<vector>

/*
* `vector& operator=(const vector &vec);`//重载等号操作符
* `assign(beg, end);`       //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`        //将n个elem拷贝赋值给本身。
*/


void printVector2(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test13() {
	std::vector<int> v1;//无参构造
	for (int i = 0; i < 10; i++) {//赋值0-10
		v1.push_back(i);
	}
	printVector2(v1);

	std::vector<int> v2 = v1;//重载运算符方式
	printVector2(v2);

	std::vector<int> v3;
	v3.assign(v1.begin(), v1.end());//assign拷贝
	printVector2(v3);

	std::vector<int> v4;
	v4.assign(10, 200);//assign 10 个200
	printVector2(v4);

}
