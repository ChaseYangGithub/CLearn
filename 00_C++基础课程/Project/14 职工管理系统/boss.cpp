#include"boss.h"
//�ϰ���

//���캯��
Boss::Boss(int id, std::string name, int dId) {
	this->id = id;
	this->name = name;
	this->deptId = dId;
}

//��ʾ������Ϣ
 void Boss::showInfo() {
	 std::cout << "ְ����ţ�" << this->id
		 << "\tְ��������" << this->name
		 << "\t��λ��" << this->getDeptName()
		 << "\t��λְ�𣺹���˾��������" << std::endl;
}
 
 //��ȡְλ��Ϣ
 std::string Boss::getDeptName() {
	 return std::string("�ܲ�");
 }