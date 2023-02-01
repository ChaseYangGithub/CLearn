#include<iostream>
using namespace std;
//µİ¼õÔËËã·ûÖØÔØ

class Name {
	friend ostream& operator<<(ostream& out, Name name);
public:
	Name() {
		this->code = 0;
	}
	//Ç°ÖÃ--
	Name& operator--() {
		code--;
		return *this;
	}
	//ºóÖÃ--
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

//µİ¼õÔËËã·ûÖØÔØ
void operatorTest4() {
	Name name;
	cout << --name << endl;
	cout << name << endl;
	cout << name-- << endl;
	cout << name << endl;
}