#include<iostream>
using namespace std;
class Buildings;//��ǰ������
class GoodGay {
public:
	GoodGay();
	void visit();
private:
	Buildings *build;
};

class Buildings {
	//���߱����� GoodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������
	friend class GoodGay;
public:
	Buildings();
public:
	string sittingRoom;
private:
	string bedRoom;
};

//����ʵ�ֳ�Ա����

Buildings::Buildings() {
	this->sittingRoom = "����";
	this->bedRoom = "����";
}

GoodGay::GoodGay() {
	//�������������
	build = new Buildings;
}
void GoodGay::visit() {
	std::cout << "�û��ѷ���:" << build->sittingRoom << endl;
	std::cout << "�û��ѷ���:" << build->bedRoom << endl;
}
void friendTest2() {
	GoodGay good;
	good.visit();
}