#include<iostream>
#include<vector>
#include<algorithm>//标准算法

void myPrint(int val) {
	std::cout << val << std::endl;
}

void test11() {
	//创建vector容器对象，并通过模板参数指定容器中存储的数据类型
	std::vector<int> v;
	//向容器中存放数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	//每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	//v.begin()返回迭代器，这个迭代器指向容器中第一个数据
	//v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
	//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
	std::vector<int>::iterator pBegin = v.begin();
	std::vector<int>::iterator pEnd = v.end();

	//第一种遍历方式：
	while (pBegin != pEnd) {
		std::cout << *pBegin << std::endl;
		pBegin++;
	}
	//第二种遍历方式：
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	//第三种遍历方式：
	//使用STL提供标准遍历算法  头文件 algorithm
	for_each(v.begin(), v.end(), myPrint);
}