#include<iostream>
#include<stack>

void test42() {
	//����ջ������վ������������Ƚ��ȳ�
	std::stack<int> s;
	//��ջ��������ݣ�����ѹջ ��ջ
	s.push(10);
	s.push(20);
	s.push(30);

	while (!s.empty()) {
		//���ջ��Ԫ��
		std::cout << "ջ��Ԫ��Ϊ��" << s.top() << std::endl;
		//����ջ��Ԫ��
		s.pop();
	}
	std::cout << "ջ�Ĵ�СΪ��" << s.size() << std::endl;
}