#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//�ļ���ȡ����
void fileRead() {
	//����������
	ifstream ifs;
	//���ļ��ж��ļ��Ƿ����
	ifs.open("text.txt",ios::in ); //Ϊ���ļ������ļ�
	if (!ifs.is_open()) {//�ж��ļ��Ƿ�򿪳ɹ�
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//���������ʽ
	//��һ��
	
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {//����һ�����ݷ��ؼٵı�־
	//	cout << buf << endl;
	//}
	
	//�ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))) {//��ȡ������ ��ȡ���ݵ�ָ�룬����ȡ���ݵ���Ŀ����
	//	cout << buf << endl;
	//}

	//������
	//string buf;
	//while (getline(ifs,buf)) {//������string�ڣ����ֱ��ʹ��std�����ռ���ʾȱʧ�������ǰ汾���⣬ͬ���ĵڶ��ַ����еĿ���
	//	cout << buf <<endl;
	//}
	
	//������--���Ƽ���
	char c;
	while ((c = ifs.get()) != EOF) {//ÿ�ζ�ȡһ���ַ� EOF: end of file
		cout << c;
	}
	//�ر��ļ�
	ifs.close();
}
