#include<iostream>
using namespace std;

class Mess {
	friend ostream& operator<<(ostream& out, Mess mess);
public:
	Mess() {
		this->duck = 0;
	}
	//ǰ��++ ��+�󷵻� ����������Ϊ��һֱ��һ�����ݽ������
	Mess& operator++() {
		duck++;
		return *this;
	}
	//����++ �ȷ����ٸ�ֵ
	Mess operator++(int) { //int����ռλ�����������������ֲ����ͺ��ò���
		Mess temp = *this;//��¼��ǰ�����ֵ��Ȼ���ñ����ֵ��1�����Ƿ��ص�����ǰ��ֵ���ﵽ�ȷ��غ�++��
		duck++;
		return temp;
	}
private:
	int duck;
};
ostream& operator<<(ostream& out, Mess mess) {
	out << mess.duck;
	return out;
}

void operatorTest3() {
	Mess mess;
	cout << ++mess << endl;
	cout << mess << endl;
	cout <<mess++ << endl;
	cout << mess << endl;
}