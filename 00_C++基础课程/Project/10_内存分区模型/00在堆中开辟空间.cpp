#include<iostream>
using namespace std;


//堆区数据由程序员管理开辟和释放
//堆区数据利用new关键字进行开辟内存
//​	C++中利用 new操作符在堆区开辟数据
//​	堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符  delete 
//​	语法：new 数据类型
//​	利用new创建的数据，会返回该数据对应的类型的指针
int* Func() {
	int* a = new int(10);
	return a;
}
int main() {
	int* p = Func();
	cout << *p << endl;
	cout << *p << endl;

	//利用delete释放空间
	delete p;
	//cout << *p << endl;	//此处会报错
	cout << "堆区开辟数组！" << endl;
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	//释放数组delete后加[]
	delete[]arr;
	//cout << arr[0] << endl;
	return 0;
}