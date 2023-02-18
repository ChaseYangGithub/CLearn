#include<iostream>
void test77() {
	//方式1
	std::pair<std::string, int> p(std::string("Tom"), 20);
	std::cout << p.first << " " << p.second << std::endl;
	//方式2
	std::pair<std::string, int> p2 = std::make_pair("Jerry", 21);
	std::cout << p2.first << " " << p2.second << std::endl;
}
