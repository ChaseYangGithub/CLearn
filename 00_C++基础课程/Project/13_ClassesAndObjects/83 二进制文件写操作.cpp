#include<iostream>
#include<fstream>
using namespace std;
//�������ļ�д����

class Append {
public:
	//ע��ʹ�ö����ƶ�дʱ���ʹ�СҪһ��
	char name[64];	//�ļ����ʹ���ַ��������ַ�������ΪC++���ļ���Cд��
	int age;
};

//�������ļ�д����
void binaryWriter() {
	//�������������
	ofstream ofs("person.txt", ios::out | ios::binary);//д�ļ� �����Ʒ�ʽ
	//���ļ�
	//ofs.open("person.txt", ios::out | ios::binary);//���Ϸ��ȼ�
	Append a = { "����",13};
	//д�ļ�
	ofs.write((const char*)&a, sizeof(a));//ʹ�õ�����ָ�룬��С
	//�ر��ļ�
	ofs.close();

}