#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
/*
��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
*/

class Person {
public:
	Person(std::string name, int score) {
		this->name = name;
		this->score = score;
	}
public:
	std::string name;//����
	int score;//�ɼ�
};

//��������
void createPerson(std::vector<Person>& v) {
	std::string str = "ABCDE";
	for (int i = 0; i < 5; i++) {
		std::string name = "ѡ��";
		name += str[i];
		int score = 0;
		Person p(name, score);
		//�������Ķ���洢��������
		v.push_back(p);
	}
}
//���
void setScore(std::vector<Person>& v) {
	for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//����ί�ĳɼ��ŵ�deque������
		std::deque<int> d;
		for (int i = 0; i < v.size(); i++) {
			int score = std::rand() % 41 + 60;//60-100
			d.push_back(score);
		}
		//����
		std::sort(d.begin(), d.end());
		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();
		//ȡƽ����
		int sum = 0;
		for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
			sum += *it;//�ۼӷ���
		}
		int avg = sum / d.size();
		//��ƽ���ָ�ֵ��ѡ��
		it->score = avg;
	}

}
//��ʾ�ɼ�
void showScore(std::vector<Person>& v) {
	for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "������" << it->name << " �ɼ���" << it->score<<std::endl;
	}
}

void test31() {
	//�������
	srand((unsigned int)time(NULL));
	//����ѡ��
	std::vector<Person> v;//���ѡ������
	createPerson(v);
	//���
	setScore(v);
	//��ʾ���÷�
	showScore(v);
}