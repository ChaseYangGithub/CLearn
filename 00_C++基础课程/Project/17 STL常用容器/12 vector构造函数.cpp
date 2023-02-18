#include<iostream>
#include<vector>
/*
* `vector<T> v; `               		     //采用模板实现类实现，默认构造函数
* `vector(v.begin(), v.end());   `       //将v[begin(), end())区间中的元素拷贝给本身。
* `vector(n, elem);`                            //构造函数将n个elem拷贝给本身。
* `vector(const vector &vec);`         //拷贝构造函数。
*/


//打印vector数据
void printVector(std::vector<int>& v) {
	//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
}
//vector 构造函数
void test12() {
	std::vector<int> v1;//无参构造
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);//向v1中添加数据
	}
	printVector(v1);

	std::vector<int> v2(v1.begin(), v1.end());//将 v1从 头 到 尾 赋值给v2
	printVector(v2);
	std::vector<int> v3(10, 100);//将10个100赋值给v3
	printVector(v3);
	std::vector<int> v4(v3);
	printVector(v4);//拷贝构造函数
}
