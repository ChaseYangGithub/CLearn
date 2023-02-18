#include<iostream>
#include<map>
//��ӡ��������
void printMap3(std::map<int, int>& m) {
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << " " << it->second << " ";
	}
	std::cout << std::endl;
}

void test84() {
	std::map<int, int> m;
	//��ʽ1
	m.insert(std::pair<int, int>(1, 10));
	//��ʽ2
	m.insert(std::make_pair(2, 100));
	//��ʽ3
	m.insert(std::map<int, int>::value_type(3, 30));
	//��ʽ4
	m[4] = 40;
	printMap3(m);
	//ɾ��
	m.erase(m.begin());
	printMap3(m);
	m.erase(3);
	printMap3(m);
	//���
	m.erase(m.begin(), m.end());
	m.clear();
	printMap3(m);


}