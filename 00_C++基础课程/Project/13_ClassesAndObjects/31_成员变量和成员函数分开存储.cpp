#include<iostream>
using namespace std;
//��Ա�����ͳ�Ա�����ֿ��洢

//��ͼ��
class Graph {
	int g_a;//�Ǿ�̬��Ա��������Ķ��󣬴洢������
	static int g_b;//��̬��Ա�����������Ա ���洢������
	void func() {};	//�Ǿ�̬��Ա���� ��������Ķ��󣬾�̬����Ҳ��
};
int Graph::g_b = 1;




//��Ա�����ͳ�Ա����
void useSize() {
	Graph g;
	//�ն���ռ�ô�СΪ1
	cout << "��С:" << sizeof(g) << endl;
}