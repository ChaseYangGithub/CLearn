#include<iostream>
using namespace std;
//��̬��������

//������
class Zoon {
public:
	//����ǰ�����virtual�ؼ��֣�����麯������ô�������ڱ����ʱ��Ͳ���ȷ�����������ˡ�
	virtual void speak() {
		cout << "����˵��" << endl;
	}
};
//è��
class Cat :public Zoon {
public:
	void speak() {
		cout << "è˵��" << endl;
	}
};
//����
class Dog :public Zoon {
public:
	void speak() {
		cout << "��˵��" << endl;
	}
};
//ִ��˵��
//����ϣ������ʲô������ô�͵���ʲô����ĺ���
//���������ַ�ڱ���׶ξ���ȷ������ô��̬����
//���������ַ�����н׶β���ȷ�������Ƕ�̬����
void doSpeak(Zoon& zoon) {	// Zoon &zoon =	cat; ��������û���ָ��ָ������Ķ���
	zoon.speak();
}
//��̬���������� 
//1���м̳й�ϵ 
//2��������д�����е��麯��
//��̬ʹ�ã�
//����ָ�������ָ���������
void multyTest() {
	Cat cat;
	doSpeak(cat);
	Zoon zoon;
	doSpeak(zoon);
}
//��д����������ֵ����  ������ �����б� ��ȫһ�³�Ϊ��д