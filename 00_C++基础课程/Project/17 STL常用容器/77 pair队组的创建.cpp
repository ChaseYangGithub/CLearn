#include<iostream>
void test77() {
	//��ʽ1
	std::pair<std::string, int> p(std::string("Tom"), 20);
	std::cout << p.first << " " << p.second << std::endl;
	//��ʽ2
	std::pair<std::string, int> p2 = std::make_pair("Jerry", 21);
	std::cout << p2.first << " " << p2.second << std::endl;
}
