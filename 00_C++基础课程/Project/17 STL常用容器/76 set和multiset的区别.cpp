#include<iostream>
#include<set>

void test76() {
	std::set<int> s;
	std::pair<std::set<int>::iterator, bool> ret = s.insert(10);//�������ݷ�����������Ϊpair<��������iterator ��bool> bool�����ɹ�ʧ�ܡ�������
	if (ret.second) {//ret.second��ʾ��������ret���յĵڶ�������
		std::cout << "��һ�β���ɹ�" << std::endl;
	}
	else {
		std::cout << "��һ�β���ʧ��" << std::endl;
	}
	ret = s.insert(10);
	if (ret.second) {
		std::cout << "��2�β���ɹ�" << std::endl;
	}
	else {
		std::cout << "��2�β���ʧ��" << std::endl;
	}
	//multiset
	std::multiset<int> m;
	m.insert(10);
	m.insert(10);
	for (std::multiset<int>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}