#include<iostream>
using namespace std;
/*
	��Ա��������Ϊ˽��
	�ŵ㣺
		�����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
		����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
*/

class Person {
public:
	//�������ÿɶ���д
	void setName(string name) {
		uname = name;
	}
	string getName() {
		return uname;
	}
	//��ȡ����
	int getAge() {
		return uage;
	}
	//��������
	void setAge(int age) {
		if (age < 0 || age>150) {
			uage = 0;
			cout << "���������" << endl;
			return;
		}
		uage = age;
	}
	//�������ÿ�д
	void setLove(string love) {
		ulove = love;
	}
private:
	string uname;//�ɶ���д ����
	int uage;//ֻ��  ����	//�����������ǰ�汨��
	string ulove;//ֻд ����

	//�·������ʹ��Person p;��ʽ������󲻱���
	//string ulove;//ֻд ����
	//int uage;//ֻ��  ����	//�����������ǰ�汨��
	
};

void privateAttribute() {
	
	
	/*
		��ʹ��Person p��ʽʱ ����
		δʹ����ʾ�ķ�ʽnew�����¶������malloc,�����ڴ��δ���ù��캯����ʼ��
		ԭ��
		ʹ�ýṹ��������Ͷ���һ���ṹ��ʱ(Type a)����Ϊ���̻�����������ԭ���±������Ըñ���ֻʹ��malloc�����ڴ棬
		û�е�����Ӧ�Ĺ��캯�����ڲ������ݳ�ʼ����������Ҫ��ָ�����ݣ��ͻ���ָ�����������string������������
		���������
		����Ա��Ҫ��ʽ��ʹ��new�������(Type *a=new Type())�������ǽṹ������������Ҳ������ָ�����ֵ����

		ע��㣺
		��ʽʹ����new�Ժ����Ҫ��ָ��ָ����ڴ棬������ʹ�ö���ʱ��Ϊ�˱�����������ֻ��mallocû�й�����������Ҫʹ��ָ�����ֵ���󣬴�ֵ��ʱ��ֻ��Ҫ��ָ������þͿ��ԡ�

	*/
	//Person p;
	Person *p=new Person();
	//��������
	p->setName("����");
	cout << "������" << p->getName() << endl;
	//��������
	p->setAge(21);
	cout << "���䣺" << p->getAge() << endl;
	//��������
	p->setLove("�Ծ���");
	//cout << "���ˣ�" << p->ulove << endl;//ֻд���ԣ����ɶ�ȡ

}
