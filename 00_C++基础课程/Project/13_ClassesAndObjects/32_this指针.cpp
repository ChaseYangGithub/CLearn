#include<iostream>
using namespace std;
//thisָ��

//�߶���
class Height {
	//thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
	//thisָ�벻��Ҫ���壬ֱ��ʹ�ü���
public:
	int h_a;
	Height() {

	}
	Height(int h_a) {
		//���βκͳ�Ա����ͬ��ʱ������thisָ��������
		this->h_a = h_a;
	}
	Height& heightAddHeight(Height &h) {//Ҫ�����ô��ݷ���ֵ�����ʹ��ֵ���� ��ʽ���ݻ�һֱ����
		this->h_a += h.h_a;
		//���ض�����
		return *this;
	}


};
//thisָ�����
void thisTest() {
	Height h(21);
	cout << "h_a=" << h.h_a << endl;

	Height h2(3);
	//��ʽ���˼��
	h2.heightAddHeight(h).heightAddHeight(h).heightAddHeight(h);
	cout << "p2 h_a=" << h2.h_a << endl;
}