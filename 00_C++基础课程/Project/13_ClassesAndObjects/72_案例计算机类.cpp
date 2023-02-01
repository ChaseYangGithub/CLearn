#include<iostream>
using namespace std;
/*
����������
�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������

��̬���ŵ㣺
* ������֯�ṹ����
* �ɶ���ǿ
* ����ǰ�ںͺ��ڵ���չ�Լ�ά��

*/
//��ͨʵ��
class Calculate {
public:
	int getResult(string op) {
		if (op == "+") {
			return num1 + num2;
		}
		else if (op == "-") {
			return num1 - num2;
		}
		else if (op == "*") {
			return num1 * num2;
		}
		else {
			return -1;
		}
		//���Ҫ�ṩ�µ����㣬��Ҫ�޸�Դ��
	}
public:
	int num1;
	int num2;
};
//��̬ʵ��
//�����������
//��̬�ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��
class AbstrateCalculate {
public:
	virtual int getResult() {
		return 0;
	}
public:
	int num1;
	int num2;
};
//�ӷ�������
class AddCalculate :public AbstrateCalculate {
public:
	int getResult() {
		return num1 + num2;
	}
};
//����������
class SubCalculate :public AbstrateCalculate {
	int getResult() {
		return num1 - num2;
	}
};
//�˷�������
class MulCalculate :public AbstrateCalculate {
	int getResult() {
		return num1 * num2;
	}
};
void polymorTest() {
	//��ͨʵ�ֲ���
	Calculate c;
	c.num1 = 10;
	c.num2 = 10;
	cout << c.num1 << " + " << c.num2 << " = " << c.getResult("+") << endl;
	cout << c.num1 << " - " << c.num2 << " = " << c.getResult("-") << endl;
	cout << c.num1 << " * " << c.num2 << " = " << c.getResult("*") << endl;

	//��̬ʵ�ֲ���
	AbstrateCalculate* abc = new AddCalculate();
	abc->num1 = 10;
	abc->num2 = 10;
	cout << abc->num1 << " + " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;//��������
	AbstrateCalculate* a = new SubCalculate();
	a->num1 = 10;
	a->num2 = 10;
	cout << a->num1 << " - " <<a->num2 << " = " << a->getResult() << endl;
	delete a;//��������
	AbstrateCalculate* b = new MulCalculate();
	b->num1 = 10;
	b->num2 = 10;
	cout << b->num1 << " * " << b->num2 << " = " << b->getResult() << endl;
	delete b;//��������
}