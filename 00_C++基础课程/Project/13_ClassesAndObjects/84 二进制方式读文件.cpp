#include<iostream>
#include<fstream>
using namespace std;
//�����Ʒ�ʽ���ļ�

class Base {
public:
	//ע��ʹ�ö����ƶ�дʱ���ʹ�СҪһ��
	char name[64];
	int age;
};

//�������ļ���ȡ����
void binaryRead() {
	//������������Զ����Ƶķ�ʽ��ȡ
	ifstream ifs("person.txt", ios::in | ios::binary);
	//�ж��Ƿ��ȡ�ɹ�
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	Base b;
	ifs.read((char*)&b, sizeof(b));//readʹ�ö����Ʒ�ʽ��ȡ����
	cout << "������" << b.name << "���䣺" << b.age;
}