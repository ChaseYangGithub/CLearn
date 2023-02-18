#include<iostream>
#include<stack>

void test42() {
	//创建栈容器，站容器必须符合先进先出
	std::stack<int> s;
	//向栈中添加数据，叫做压栈 入栈
	s.push(10);
	s.push(20);
	s.push(30);

	while (!s.empty()) {
		//输出栈顶元素
		std::cout << "栈顶元素为：" << s.top() << std::endl;
		//弹出栈顶元素
		s.pop();
	}
	std::cout << "栈的大小为：" << s.size() << std::endl;
}