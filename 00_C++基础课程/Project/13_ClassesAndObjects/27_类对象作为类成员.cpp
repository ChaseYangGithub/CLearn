#include<iostream>
using namespace std;
//�������Ϊ���Ա

//�������
class Elephant {
public:
	Elephant(string name) {
		ename = name;
		cout << "Elephant�����캯��" << endl;
	}
	~Elephant() {
		cout << "Elephant������������" << endl;
	}
public:
	string ename;//��������
};
//�������
class Animal {
public:
	//��ʼ���б���Ը��߱�����������һ�����캯��
	Animal(string namea,string namee):aname(namea),e(namee){
		cout << "����Ĺ��캯��" << endl;
	}
	~Animal() {
		cout << "�������������" << endl;
	}
	void showAnimal() {
		cout << aname << "ʹ��������" << e.ename<< endl;
	}
public:
	string aname;
	Elephant e;
};


//�������Ϊ���Ա����
void testClass() {
	//�����г�Ա�����������ʱ�����ǳƸó�ԱΪ �����Ա
	//�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
	//����˳���빹���෴
	Animal a("����", "�˶���");
	a.showAnimal();
}