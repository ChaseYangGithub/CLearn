#ifndef WorkerManager_H	//��ֹͷ�ļ����ظ������ͱ��� һ����������Ϊ�ļ�����д����H,C++ 5th�Ƽ����»���6thû��
#define WorkerManager_H
#include "worker.h"
#include<fstream>	//�����ļ�����
#define FILENAME "empFile.txt"//�洢�ļ�������
//ְ����
class WorkerManager {
public:
	//���캯��
	WorkerManager();
	//��������
	~WorkerManager();
	//����ļ�
	void clearFile();
	//������Ϣ
	void sortEmp();
	//����ְ����Ϣ
	void findEmp();
	//�޸�ְ����Ϣ
	void modEmp();
	//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
	int isExit(int id);
	//ɾ��ְ��
	void delEmp();
	//��ʾְ��
	void showEmp();
	//��ʼ���ļ���Ա��
	void initEmp();
	//ͳ���ļ��е�����
	int getNum();
	//�����ļ�
	void save();
	//չʾ�˵�
	void showMenu();
	//�˳�����
	void exitSystem();
	//����ְ��
	void addEmp();
public:
	//��¼�ļ��е���������
	int empNum;
	//Ա�������ָ��
	Worker** empArray;//����ָ�����ݸ�ʽΪָ���ָ��
	//�ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
};
#endif
//VSĬ��#pragma once����ʹ����֧�ָ��ӹ㷺��ifndef