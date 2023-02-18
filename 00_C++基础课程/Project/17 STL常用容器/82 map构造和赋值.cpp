#include<iostream>
#include<map>

//��ӡ��������
void printMap(std::map<int, int>& m) {
	for (std::map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout <<it->first<<" "<<it->second << " ";
	}
	std::cout << std::endl;
}

void test82() {
	std::map<int, int> m;//Ĭ�Ϲ���
	m.insert(std::pair<int, int>(1, 10));
	m.insert(std::pair<int, int>(2, 20));
	m.insert(std::pair<int, int>(3, 30));
	m.insert(std::pair<int, int>(4, 40));
	printMap(m);
	//��������
	std::map<int, int> m2(m);
	printMap(m2);
	
	std::map<int, int> m3 = m2;//��ֵ
	printMap(m3);
}