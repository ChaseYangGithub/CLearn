#include<iostream>
using namespace std;

//���μ̳д�������Ҫ����������̳�������ͬ�����ݣ�������Դ�˷��Լ���������
//������̳п��Խ�����μ̳�����
class Animal {
public:
	int age;
};

//�̳�ǰ��virtual�ؼ��ֺ󣬱�Ϊ��̳�
//��ʱ�����ĸ���Animal��Ϊ�����

class Sheep :virtual public Animal {};
class Tuo :virtual public Animal {};
class SheepTuo :public Sheep, public Tuo {};

void virtualInherit() {
	SheepTuo t;
	t.Sheep::age = 100;
	t.Tuo::age = 200;
	cout << "t.Sheep::age = " << t.Sheep::age << endl;
	cout << "t.Tuo::age = " << t.Tuo::age << endl;
	cout << "t.age = " << t.age << endl;
}