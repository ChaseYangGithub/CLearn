#include "manager.h"
//������

//���캯��
Manager::Manager(int id, std::string name, int dId) {
	this->id = id;
	this->name = name;
	this->deptId = dId;
}

//��ʾ������Ϣ
void Manager::showInfo() {
	std::cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻���������·������Ա��" << std::endl;
}

//��ȡ��λ��Ϣ
std::string Manager::getDeptName() {
	return std::string("����");
}