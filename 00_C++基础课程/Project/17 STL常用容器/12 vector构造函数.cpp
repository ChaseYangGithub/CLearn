#include<iostream>
#include<vector>
/*
* `vector<T> v; `               		     //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
* `vector(v.begin(), v.end());   `       //��v[begin(), end())�����е�Ԫ�ؿ���������
* `vector(n, elem);`                            //���캯����n��elem����������
* `vector(const vector &vec);`         //�������캯����
*/


//��ӡvector����
void printVector(std::vector<int>& v) {
	//vector<int>::iterator �õ�vector<int>���������ĵ���������
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
}
//vector ���캯��
void test12() {
	std::vector<int> v1;//�޲ι���
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);//��v1���������
	}
	printVector(v1);

	std::vector<int> v2(v1.begin(), v1.end());//�� v1�� ͷ �� β ��ֵ��v2
	printVector(v2);
	std::vector<int> v3(10, 100);//��10��100��ֵ��v3
	printVector(v3);
	std::vector<int> v4(v3);
	printVector(v4);//�������캯��
}
