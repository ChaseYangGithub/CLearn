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

//��ϵ�����
void operatorTest6() {
	Play a("Jocelyn Pook", 50);
	Play b("Gabriela Bee", 17);
	if (a == b) {
		cout << "���" << endl;
	}
	else {
		cout << "����" << endl;
	}
	if (a != b) {
		cout << "����" << endl;
	}
	else {
		cout << "���" << endl;
	}
}