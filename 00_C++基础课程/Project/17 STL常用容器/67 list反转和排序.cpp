#include<iostream>
#include<list>
//��ֵ���
void printList7(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << *it <<" ";
	}
	std::cout << std::endl;
}
//�Ƚ�
bool myCompare(int val1,int  val2) {
	//����val1>val2
	return val1 > val2;
}
void test67() {
	std::list<int> l;
	l.push_back(1);
	l.push_back(12);
	l.push_back(13);
	l.push_back(14);
	printList7(l);
	//��ת����
	l.reverse();
	printList7(l);
	//����
	//���в�֧��������ʵ�������������������ʹ�ñ�׼�㷨
	//��֧��������ʵ��������㷨���ڲ����ṩ��Ӧ���㷨
	l.sort();//Ĭ�ϴ�С����
	printList7(l);
	l.sort(myCompare);//ָ������ ����
	printList7(l);
}
