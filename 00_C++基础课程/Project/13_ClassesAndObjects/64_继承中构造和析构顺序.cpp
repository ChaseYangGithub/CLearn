#include<iostream>
using namespace std;

class Study {
public:
	Study() {
		cout << "Study���캯��" << endl;
	}
	~Study() {
		cout << "Study��������" << endl;
	}
};

class Learn :public Study{
public:
	Learn() {
		cout << "Learn���캯��" << endl;
	}
	~Learn() {
		cout << "Learn��������" << endl;
	}
};

void inheritTest2() {
	Learn l;//�̳����ȵ��ø��๹�캯�����ڵ������๹�캯����������֮�෴

}