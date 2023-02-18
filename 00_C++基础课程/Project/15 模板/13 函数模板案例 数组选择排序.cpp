#include<iostream>

//����������
//
//* ���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
//* �������Ӵ�С�������㷨Ϊѡ������
//* �ֱ�����char����� int������в���

//�����ĺ���ģ��
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//ѡ����������Ӵ�С����
template<class T>
void mySort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i+1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		if (max != i) {//���ֵ����i��������
			mySwap(arr[max], arr[i]);
		}
		
	}
}

//�������ģ��
template<class T>
void myPrint(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

//����ģ�尸������
void test13() {
	//����int����
	int intArr[] = { 7,5,3,4,2,4,6,7,3,5};
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	myPrint(intArr, num);

	//����char����
	char charArr[] = "abcdefg";
	num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	myPrint(charArr, num);
}