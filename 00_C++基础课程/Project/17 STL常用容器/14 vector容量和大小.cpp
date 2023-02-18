#include<iostream>
#include<vector>


void printVector3(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test14() {
	std::vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector3(v1);
	if (v1.empty()) {
		std::cout << "v1为空" << std::endl;
	}
	else {
		std::cout << "v1不为空" << std::endl
			<< "v1的容量=" << v1.capacity() << std::endl
			<< "v1的大小=" << v1.size() << std::endl;
	}
	//resize重新指定大小,若更大，用10填充数据
	v1.resize(15, 10);
	printVector3(v1);
	//resize 若更小，删除超出部分
	v1.resize(5);
	printVector3(v1);
}