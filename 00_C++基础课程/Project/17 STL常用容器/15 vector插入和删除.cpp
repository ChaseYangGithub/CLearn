#include<iostream>
#include<vector>

//输出容器数据
void printVector4(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
//vector插入和删除
void test15() {
	std::vector<int> v;
	//尾插法
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector4(v);
	//尾插
	v.pop_back();
	printVector4(v);
	//插入 迭代器指向的位置插入指定数据
	v.insert(v.begin(), 100);
	printVector4(v);
	//插入 迭代器指向的位置插入 n个指定数据
	v.insert(v.begin(), 2, 1000);
	printVector4(v);
	//删除迭代器指向的元素
	v.erase(v.begin());
	printVector4(v);
	//清空
	v.erase(v.begin(), v.end());//删除迭代器指向区间的数据
	v.clear();//删除容器中所有元素
	printVector4(v);
}