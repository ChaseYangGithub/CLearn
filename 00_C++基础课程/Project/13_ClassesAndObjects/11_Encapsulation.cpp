#include<iostream>
using namespace std;
/*
��װ�����������������֮һ
��װ���������ڣ�
	�����Ժ���Ϊ��Ϊһ�����壬���������е�����
	�����Ժ���Ϊ����Ȩ�޿���
		Ȩ�������֣�
		public ����
		protected ����Ȩ��
		private	˽��Ȩ��
*/



//���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class Student {
//��������
public:
	//��������
	void setName(string name) {
		uname = name;
	}
	//����id
	void setId(int id) {
		uid = id;
	}
	//��ʾѧ����Ϣ
	void showStudent() {
		cout << "name:" << uname << "ID:" << uid << endl;
	}
//����
public:
	string uname;//ѧ������
	int uid;//ѧ��id
};

//Բ����
const double PI = 3.14;
//��װԲ�࣬��Բ���ܳ�
class Circle {
public://����Ȩ�� ����
	//����
	int r;//�뾶

	//��Ϊ
	//��ȡԲ���ܳ�
	double calculateCircle() {
		//��ȡԲ���ܳ�
		return 2 * PI * r;
	}
};

//��װ����
void encapsulation() {
	//1.��������ʱ�����Ժ���Ϊд��һ�𣬱�������
		//��Բ��
	cout << "����1����Բ��" << endl;
	Circle c;//ͨ��Բ�ഴ��Բ�Ķ���
	c.r = 10;
	cout << "Բ���ܳ�Ϊ��" << c.calculateCircle() << endl;
	//��ʾѧ����Ϣ
	cout << "����2����ʾѧ����Ϣ" << endl;
	Student s;
	s.setName("����");
	s.setId(123);
	s.showStudent();
}
