#include<iostream>
#include<vector>

void printVector6(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void test17() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	printVector6(v);

	std::vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v2.push_back(10 - i);
	}
	printVector6(v2);
	//互换容器
	std::cout << "互换后：" << std::endl;
	v.swap(v2);
	printVector6(v);
	printVector6(v2);

	v.clear();
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
	}

	std::cout << "v的容量为：" << v.capacity() << std::endl
		<< "v的大小为：" << v.size() << std::endl;
	v.resize(3);//重新指定大小
	std::cout << "v的容量为：" << v.capacity() << std::endl
		<< "v的大小为：" << v.size() << std::endl;

	//收缩内存
	std::vector<int>(v).swap(v); //创建匿名对象然后使用swap函数交换空间
	std::cout << "v的容量为：" << v.capacity() << std::endl
	 << "v的大小为：" << v.size() << std::endl;
}
