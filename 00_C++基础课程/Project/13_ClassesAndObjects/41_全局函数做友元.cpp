#include<iostream>
using namespace std;
//ȫ�ֺ�����Ϊ��Ԫ
//��Ԫ�Ĺؼ�����friend

//������
class Building {
	//���߱����� goodGayȫ�ֺ��� �� Building��ĺ����ѣ����Է������е�˽������
	friend void goodGay(Building& build);

public:
	Building() {
		sittingRoom = "����";
		bedRoom = "����";
	}
public:
	string sittingRoom;//����
private:
	string bedRoom;//����
};

//�û���--ȫ�ֺ�����Ϊ��Ԫ
void goodGay(Building &build) {
	cout << "�û������ڷ��ʣ�" << build.sittingRoom << endl;
	cout << "�û������ڷ��ʣ�" << build.bedRoom << endl;//��Ҫ����Ԫ���ܷ���
}

void friendTest() {
	Building build;
	goodGay(build);
}