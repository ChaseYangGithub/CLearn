#ifndef SPEECHMANAGER
#define SPEECHMANAGER
#include<vector>
#include<map>
#include "speaker.h"
//�ݽ�������
class SpeechManager {
public:
	//�ݽ������� ���캯��
	SpeechManager();
	//�ݽ������� ��������
	~SpeechManager();
	//չʾ�˵�
	void show_Menu();
	//�˳�����
	void exitSystem();
	//��ʼ������
	void initSpeech();
	//��ʼ������ѡ��
	void createSpeaker();
	//���ԣ���ʾ����ѡ����Ϣ
	void printSpeaker();
	//��ʼ����
	void startSpeech();
	//��ӡͨ���������� ʹ�� 
	void printInt(std::vector<int> &v);
	//��ǩ
	void startDraw();
	//������
	void speechContest();
	//��ʾ��������--�������
	void showScore();
	//�������ݵ�����
	void saveRecord();
	//��ȡ���ؼ�¼
	void loadRecord();
	//��ʾ����÷�
	void showRecord();
	//��ռ�¼
	void clearRecord();
public:
	//����ѡ�� ���� 12��
	std::vector<int> v1;
	//��һ�ֽ������� 6��
	std::vector<int> v2;
	//ʤ��ǰ�������� 3��
	std::vector<int> v3;
	//��ű�ż���Ӧ����ѡ�ֵ�����
	std::map<int, Speaker> speaker;
	//��ǰ��������
	int index;
	//�ļ�Ϊ�ձ�־
	bool fileIsEmpty;
	//�����¼
	std::map<int, std::vector<std::string>> record;

};
#endif