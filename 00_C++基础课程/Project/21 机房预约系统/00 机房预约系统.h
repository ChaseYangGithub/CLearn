#ifndef MAINFUNC
#define MAINFUNC
#include<iostream>
#include"human.h"
//������˵�
void main_Menu();
//��½����
void loginIn(std::string fileName, int type);
//����Ա�˵�
void managerMenu(Human*& manager);//&˵��manager��һ������*ȷ�������õ���ָ��

//ѧ���Ӳ˵�
void studentMenu(Human*& student);

//��ʦ��½�˵�
void teacherMenu(Human*& teacher);
#endif // MAINFUNC
