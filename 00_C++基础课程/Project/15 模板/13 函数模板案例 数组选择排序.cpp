#include<iostream>

//案例描述：
//
//* 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//* 排序规则从大到小，排序算法为选择排序
//* 分别利用char数组和 int数组进行测试

//交换的函数模板
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//选择排序数组从大到小排序
template<class T>
void mySort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i+1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		if (max != i) {//最大值不是i交换数据
			mySwap(arr[max], arr[i]);
		}
		
	}
}

//输出数组模板
template<class T>
void myPrint(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

//函数模板案例测试
void test13() {
	//测试int数组
	int intArr[] = { 7,5,3,4,2,4,6,7,3,5};
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	myPrint(intArr, num);

	//测试char数组
	char charArr[] = "abcdefg";
	num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	myPrint(charArr, num);
}