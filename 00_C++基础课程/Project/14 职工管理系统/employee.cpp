#include "employee.h"
//ְ����

//���캯��
Employee::Employee(int id, std::string name, int dId) {
	this->id = id;
	this->name = name;
	this->deptId = dId;
}

//��ʾ������Ϣ
void Employee::showInfo() {
	std::cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << std::endl;
}

//��ȡ��λ����
std::string Employee::getDeptName() {
	return std::string("Ա��");
}