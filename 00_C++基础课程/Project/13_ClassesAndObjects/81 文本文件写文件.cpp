#include<iostream>
#include<fstream>	//�����ļ���
using namespace std;
//�ı��ļ�д�ļ�

//�ı��ļ�д�ļ�����
void fileWriter() {
	//����������
	ofstream ofs;
	//���ļ�
	ofs.open("text.txt",ios::out );//Ϊд�ļ������ļ�  �ļ�Ŀ¼Ϊ��ǰ��������Ŀ¼�µ�text.txt�ļ�
	//д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	//�ر��ļ�
	ofs.close();
}