#include<iostream>
using namespace std;
class Building2;//��ǰ������
class GoodGay2 {
public:
	GoodGay2();
	void visit();//ֻ��visit������ΪBuilding�ĺ����ѣ����Է�����Building��˽������
	void visit2();
private:
	Building2* build;
};

class Building2 {
	//���߱�����  goodGay���е�visit��Ա���� ��Building�����ѣ����Է���˽������
	friend void GoodGay2::visit();
public:
	Building2();
public:
	string sittingRoom;
private:
	string bedRoom;
};

//����ʵ�ֳ�Ա����

Building2::Building2() {
	this->sittingRoom = "����";
	this->bedRoom = "����";
}

GoodGay2::GoodGay2() {
	//�������������
	build = new Building2;
}
void GoodGay2::visit() {
	std::cout << "�û��ѷ���:" << build->sittingRoom << endl;
	std::cout << "�û��ѷ���:" << build->bedRoom << endl;
}
void GoodGay2::visit2() {
	std::cout << "�û��ѷ���:" << build->sittingRoom << endl;
	//std::cout << "�û��ѷ���:" << build->bedRoom << endl;
}
void friendTest3() {
	GoodGay2 good;
	good.visit();
}