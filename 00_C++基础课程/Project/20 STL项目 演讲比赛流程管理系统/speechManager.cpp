#include "speechManager.h"
#include<iostream>
#include<algorithm>//�㷨
#include<ctime>//�����
#include<deque>//˫�˶���
#include<numeric>//���������㷨
#include<fstream>//�ļ���д
//�ݽ������� ���캯��
SpeechManager::SpeechManager() {
	//��ʼ������
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
	//��ȡ�����¼
	this->loadRecord();
}
//�ݽ���������������
SpeechManager::~SpeechManager() {

}
//չʾ����
void SpeechManager::show_Menu() {
	std::cout << "********************************************" << std::endl;
	std::cout << "*************  ��ӭ�μ��ݽ����� ************" << std::endl;
	std::cout << "*************  1.��ʼ�ݽ�����  *************" << std::endl;
	std::cout << "*************  2.�鿴�����¼  *************" << std::endl;
	std::cout << "*************  3.��ձ�����¼  *************" << std::endl;
	std::cout << "*************  0.�˳���������  *************" << std::endl;
	std::cout << "********************************************" << std::endl;
	//std::cout << "��ѡ���ܣ�" << std::endl;
	std::cout << std::endl;
}
//�˳�����
void SpeechManager::exitSystem() {
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);//���I/O���������˳�����
}
//��ʼ������
void SpeechManager::initSpeech() {
	//��֤��������Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->speaker.clear();
	//��ʼ����������
	this->index = 1;
	//��ʼ����¼����
	this->record.clear();
}
//��ʼ������12��ѡ��
void SpeechManager::createSpeaker() {
	std::string nameSeed = "abcdefghijkl";
	for (int i = 0; i < nameSeed.size(); i++) {
		//��ʼ������
		std::string name = "ѡ��";
		name += nameSeed[i];
		Speaker s;
		s.name = name;
		//��ʼ�����гɼ�Ϊ0
		for (int i = 0; i < 2; i++) {
			s.score[i] = 0;
		}
		//ѡ�ֱ��
		this->v1.push_back(i + 10001);//��Ӧ���
		//ѡ�ֱ�ż�ѡ����Ϣ��ϵ
		this->speaker.insert(std::make_pair(i + 10001, s));
	}
}
//���� ��ӡ����ѡ����Ϣ
void SpeechManager::printSpeaker(){
	for (std::map<int, Speaker>::iterator it = this->speaker.begin(); it != this->speaker.end(); it++) {
		std::cout << "ѡ�ֱ�ţ�" << it->first
			<< "  ������" << it->second.name
			<< "  �ɼ�1��" << it->second.score[0]
			<< "  �ɼ�2��" << it->second.score[1] << std::endl;
	}
	std::cout << std::endl;
}
//��ӡͨ����������
void SpeechManager::printInt(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
//��ǩ
void SpeechManager::startDraw() {
	std::cout << "��" << this->index << "�ֱ���--ѡ�����ڳ�ǩ" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "��ǩ���ݽ�˳�����£�" << std::endl;
	std::srand((unsigned int)time(NULL));//��֤ÿ���������ͬ
	if (this->index == 1) {//��һ�ֱ���
		std::random_shuffle(v1.begin(), v1.end());//����Ĭ������
		this->printInt(v1);//��ӡ��ǩ˳��
	}
	else {//�ڶ��ֱ���
		std::random_shuffle(v2.begin(), v2.end());//����Ĭ������
		this->printInt(v2);//��ӡ��ǩ˳��
	}
	std::cout << "-----------------------------------------------------------------------" << std::endl;
}
//������
void SpeechManager::speechContest() {
	std::cout << "��" << this->index << "�ֱ���--���ڽ���" << std::endl;
	std::multimap<double, int,std::greater<int>> groupScore;//���ڴ�ӡС������  ���ѡ�ֳɼ� ѡ�ֱ��
	std::vector<int> src;//������Ա����
	int num=0;//��¼��Ա���֣������жϷ���
	//�жϵ�ǰ�����ִ�
	if (this->index == 1) {
		src = v1;
	}
	else {
		src = v2;
	}
	//����ѡ������
	for (std::vector<int>::iterator it = src.begin(); it != src.end(); it++) {
		num++;
		//��ί���
		std::deque<double> d;//˫�˶��У��������ɾ��ͷ��β������
		double score;
		for (int i = 0; i < 10; i++) {
			score = (rand() % 401 + 600) / 10.f;//�ܷ�600-1000 
			d.push_back(score);
		}
		std::sort(d.begin(), d.end(), std::greater<double>());//����
		d.pop_back();//ȥ����ͷ�
		d.pop_front();//ȥ����߷�
		//�ܷ�
		double sum = std::accumulate(d.begin(), d.end(), 0.0f);//��ȡ�ܷ� ����0.0ȷ��Ϊ������
		//ƽ����
		double avg = sum / (double)d.size();
		//�������
		this->speaker[*it].score[this->index - 1] = avg;
		//�����������ʱ���� ��6��һ��
		groupScore.insert(std::make_pair(avg, *it));
		if (num % 6 == 0) {//����ɼ� ����ǰ��
			std::cout << "��" << num / 6 << "С��������Σ�" << std::endl;
			//����ɼ�
			for (std::multimap<double, int, std::greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++){
				std::cout << "���: " << it->second 
					<< " ������ " << this->speaker[it->second].name 
					<< " �ɼ��� " << this->speaker[it->second].score[this->index - 1] << std::endl;
			}

			int count = 0;
			//ȡǰ����
			for (std::multimap<double, int, std::greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++){
				if (this->index == 1){
					v2.push_back((*it).second);
				}
				else{
					v3.push_back((*it).second);
				}
			}
			groupScore.clear();//������ʱ����
			std::cout << std::endl;
		}
	}
	std::cout << "------------- ��" << this->index << "�ֱ������  ------------- " << std::endl;
}
//��ʾ��������--�������
void SpeechManager::showScore() {
	std::cout << "��" << this->index << "�ֽ���ѡ����Ϣ���£�" << std::endl;
	std::vector<int> v;
	if (this->index == 1) {//ȷ�Ͻ�������
		v = v2;
	}
	else {
		v = v3;
	}
	//��ӡ����ѡ����Ϣ
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "ѡ�ֱ�ţ�" << *it
			<< " ������" << speaker[*it].name
			<< " �÷֣�" << speaker[*it].score[this->index - 1]
			<< std::endl;
	}
	system("pause");
	system("cls");

}
//�������ݵ�����
void SpeechManager::saveRecord() {
	std::ofstream ofs;
	ofs.open("score.csv", std::ios::out|std::ios::app);//д�ļ���׷�ӷ�ʽ ���֪ʶ�㣺C++���� �ļ�����
	//������д���ļ���
	for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {//csv ,��ʽ
		ofs << *it << ","
			<< speaker[*it].score[1] << ",";
	}
	ofs<<std::endl;
	//�ر��ļ�
	ofs.close();
	std::cout << "��¼�Ѿ�����" << std::endl;
	this->fileIsEmpty = false;//���ļ���

}
//��ʼ����
void SpeechManager::startSpeech() {
	//��һ�ֱ���
	system("cls");
	//��ǩ
	startDraw();
	//����
	speechContest();
	//��ʾ���
	showScore();
	//�ڶ��ֱ���
	this->index++;
	//��ǩ
	startDraw();
	//����
	speechContest();
	//��ʾ���
	showScore();
	//�������
	saveRecord();
	//���������������
	//��ʼ������
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
	//��ȡ�����¼
	this->loadRecord();
	std::cout << "�����ѽ���" << std::endl;
	system("pause");
	system("cls");
}
//��ȡ���ؼ�¼
void SpeechManager::loadRecord() {
	std::ifstream ifs("score.csv", std::ios::in);//���������� ��ȡ�ļ�
	//�ļ����������
	if (!ifs.is_open()) {//�ж��ļ��Ƿ����
		std::cout << "�ļ�������" << std::endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�����Ϊ�����
	char ch;
	ifs >> ch;
	if (ifs.eof()) {//�ļ���ȡ����
		std::cout << "�ļ�Ϊ��" << std::endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);//��ȡ�����ַ��Ż�ȥ
	//��ȡ�ַ�
	std::string data;
	int num = 0;//���ݱ��
	while (ifs >> data) {//����һ�����ݷ��ؼٵı�־
		//std::cout << data << std::endl;
		std::vector < std::string> v;
		int pos = -1;//��¼ ��λ��
		int start = 0;//��¼��ǰ����λ��
		while (true) {
			pos=data.find(",", start);//��0��ʼ����","
			if (pos == -1) {
				break;//�Ҳ���
			}
			std::string tmp = data.substr(start, pos - start);//�ҵ��˽��зָ� ����1 ��ʼλ�� ����2��ȡ����
			v.push_back(tmp);//�洢����
			start = pos + 1;//�ָ�����
		}
		this->record.insert(std::make_pair(num, v));
		num++;
	}
	ifs.close();
}
//��ʾ����÷�
void SpeechManager::showRecord() {
	if (this->fileIsEmpty) {
		std::cout << "�ļ������ڻ���Ϊ��" << std::endl;
	}
	else {
		for (int i = 0; i < this->record.size(); i++) {//��Ϊ�����ǽ�����ʾ��
			std::cout << "��" << i + 1 << "�� " <<
				"�ھ���ţ�" << this->record[i][0] << " �÷֣�" << this->record[i][1] << " "
				"\t\t�Ǿ���ţ�" << this->record[i][2] << " �÷֣�" << this->record[i][3] << " "
				"\t\t������ţ�" << this->record[i][4] << " �÷֣�" << this->record[i][5] << std::endl;
		}
	}
	system("pause");
	system("cls");
}
//��ռ�¼
void SpeechManager::clearRecord() {
	int select = 0;
	while (select!=1&&select!=2) {//��0Ϊ��
		std::cout << "ȷ����գ�" << std::endl
			<< "1 ȷ��" << std::endl
			<< "2 ȡ��" << std::endl
			<< "���ѡ��";
		std::cin >> select;
		system("cls");
	}
	if (select == 1) {
		//��ģʽios::trunc�������ɾ�������´���
		std::ofstream ofs("score.csv", std::ios::trunc);
		ofs.close();
		//��ʼ������
		this->initSpeech();
		//����ѡ��
		this->createSpeaker();
		//��ȡ�����¼
		this->loadRecord();
		std::cout << "��ճɹ���" << std::endl;
		system("pause");
		system("cls");
	}
	else if (select == 2) {
		return;
	}
	
}