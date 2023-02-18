#include<iostream>
#include<vector>

/*
* `vector& operator=(const vector &vec);`//���صȺŲ�����
* `assign(beg, end);`       //��[beg, end)�����е����ݿ�����ֵ������
* `assign(n, elem);`        //��n��elem������ֵ������
*/


void printVector2(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void test13() {
	std::vector<int> v1;//�޲ι���
	for (int i = 0; i < 10; i++) {//��ֵ0-10
		v1.push_back(i);
	}
	printVector2(v1);

	std::vector<int> v2 = v1;//�����������ʽ
	printVector2(v2);

	std::vector<int> v3;
	v3.assign(v1.begin(), v1.end());//assign����
	printVector2(v3);

	std::vector<int> v4;
	v4.assign(10, 200);//assign 10 ��200
	printVector2(v4);

}
