#include<iostream>
using namespace std;

//�̳л�������

//����
class BasicPage {
public:
	void header() {
		cout << "����ͷ��" << endl;
	}
	void sidebar() {
		cout << "��������" << endl;
	}
	void footer() {
		cout << "�����ײ�" << endl;
	}
};

//�̳��﷨��class A : public B; 
//python����
class Python:public BasicPage {
public:
	void content() {
		cout << "Python" << endl;
	}
};
//Java��
class Java :public BasicPage {
public:
	void content() {
		cout << "Java" << endl;
	}
};

void inherit() {
	//Javaҳ��
	cout << "Javaҳ�����£� " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.sidebar();
	ja.content();
	cout << "--------------------" << endl;

	//Pythonҳ��
	cout << "Pythonҳ�����£� " << endl;
	Python py;
	py.header();
	py.footer();
	py.sidebar();
	py.content();
	cout << "--------------------" << endl;

}

