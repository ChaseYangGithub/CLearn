#include<iostream>
using namespace std;

//����Ȩ��
//����Ȩ��  public     ���ڿ��Է���  ������Է���
//����Ȩ��  protected  ���ڿ��Է���  ���ⲻ���Է��� ���ӿ��Է��ʸ��׵ı�������
//˽��Ȩ��  private    ���ڿ��Է���  ���ⲻ���Է��� ���Ӳ����Է��ʸ��׵�˽������

class Person {
	//��������Ȩ��
public:
	string name;
	//��������Ȩ��
protected:
	string car;
	//���п����� ˽��Ȩ��
private:
	int password;
public:
	void func() {
		name = "����";
		car = "������";
		password = 123456;
	}
};

//Ȩ�޿���
void accessControl() {
	Person p;
	p.name = "����";
	//p.car = "Benz";	//����Ȩ��������ʲ���
	//p.password = 123;	//˽��Ȩ��������ʲ���
}