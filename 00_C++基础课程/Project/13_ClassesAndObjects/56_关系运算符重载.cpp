#include<iostream>
using namespace std;

class Play {
public:
	Play(string name, int age) {
		this->name = name;
		this->age = age;
	}

	bool operator==(Play& p) {
		if (this->age == p.age && this->name == p.name) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(Play& p) {
		if (this->age == p.age && this->name == p.name) {
			return false;
		}
		else {
			return true;
		}
	}
	string name;
	int age;
};

//关系运算符
void operatorTest6() {
	Play a("Jocelyn Pook", 50);
	Play b("Gabriela Bee", 17);
	if (a == b) {
		cout << "相等" << endl;
	}
	else {
		cout << "不等" << endl;
	}
	if (a != b) {
		cout << "不等" << endl;
	}
	else {
		cout << "相等" << endl;
	}
}