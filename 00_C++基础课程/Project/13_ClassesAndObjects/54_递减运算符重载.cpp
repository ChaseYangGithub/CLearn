#include<iostream>
using namespace std;
//�ݼ����������

class Name {
	friend ostream& operator<<(ostream& out, Name name);
public:
	Name() {
		this->code = 0;
	}
	//ǰ��--
	Name& operator--() {
		code--;
		return *this;
	}
	//����--
	Name operator--(int) {
		Name temp = *this;
		code--;
		return temp;
	}


private:
	int code;
};

ostream& operator<<(ostream& out, Name name) {
	out << name.code;
	return out;
}

//�ݼ����������
void operatorTest4() {
	Name name;
	cout << --name << endl;
	cout << name << endl;
	cout << name-- << endl;
	cout << name << endl;
}