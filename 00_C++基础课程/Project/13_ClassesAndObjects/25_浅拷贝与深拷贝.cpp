#include<iostream>
using namespace std;
//ǳ���������
/*
	ǳ�������򵥵ĸ�ֵ��������
	// cheight=p.cheight;
	������ڶ�����������ռ䣬���п�������
	//cheight = new int(*p.cheight);

	����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������
*/
class Cat {
public:
	//�޲Σ�Ĭ�ϣ����캯��
	Cat() {
		cout << "�޲ι��캯��" << endl;
	}
	//�вι��캯��
	Cat(int age,int height) {
		cout << "�вι��캯��" << endl;
		cage = age;
		cheight = new int(height);
	}
	//�������캯��
	Cat(const Cat& p) {
		cout << "�������캯��" << endl;
		//�������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ����ͷŶ�������
		//ǳ����ָ�����͸�����ͬ�ĵ�ַ�����Ǹõ�ַֻ���ͷ�һ�Σ��ٴ��ͷ���Ƿ�����
		// cheight=p.cheight;
		//���ָ�������ڶ��������µĿռ�洢ԭָ��ָ������ݲ��洢��Ӧ��ַ
		//cheight = new int(*p.cheight);
		cage = p.cage;
		cheight = new int(*p.cheight); 
	}
	//��������
	~Cat() {
		cout << "��������" << endl;
		//�������룬���������ٵ����ݽ����ͷ�
		if (cheight != NULL) {
			delete cheight;
			cheight = NULL;
		}
	}
public:
	int cage;	//����
	int *cheight;//�߶�
};

//ǳ�������������
void shallowCopyAndDeepCopy() {
	Cat c1(21,174);
	Cat c2(c1);
	cout << "c1�����䣺" << c1.cage << "��ߣ�" << *c1.cheight << endl;
	cout << "c2�����䣺" << c2.cage << "��ߣ�" << *c2.cheight << endl;
}