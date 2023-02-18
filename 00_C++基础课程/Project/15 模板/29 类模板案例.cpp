#include<iostream>
#include "myArray.h"

//构造函数
template<class T>
MyArray<T>::MyArray(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->address = new T[this->capacity];//根据用户数据创建初始空间
}

//拷贝构造函数
template<class T>
MyArray<T>::MyArray(const MyArray& arr) {
	this->capacity = arr.capacity;
	this->size = arr.size;
	this->address = new T[this->capacity];//创建新空间
	for (int i = 0; i < this->size; i++) {//复制数据
		//如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
		// 普通类型可以直接= 但是指针类型需要深拷贝
		if (i < this->capacity - 1) {
			this->address[i] = arr.address[i];

		}
	}
}



//重载=操作符 防止浅拷贝问题
template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray& arr) {//此处注意要确定MyArray所有数据类型，所以返回值有<T> ，可能表述不准确
	if (this->address != NULL) {//拷贝空间不为空
		delete[] this->address;
		this->capacity = 0;
		this->size = 0;
	}
	this->capacity = arr.capacity;
	this->size = arr.size;
	this->address = new T[this->capacity];//创建新空间
	for (int i = 0; i < this->size; i++) {//复制数据
		this->address[i] = arr.address[i];
	}
	return *this;
}

//重载[]实现通过下标访问数据
template<class T>
T& MyArray<T>::operator[](int index) {
	if (this->size <= index) {
		std::cout << "越界" << std::endl;
	}
	return this->address[index];
}

//尾插法
template<class T>
void MyArray<T>::pushBack(const T&t) {
	if (this->capacity == this->size) {//空间满
		return;
	}
	this->address[this->size] = t;
	this->size++;
}

//尾删法
template<class T>
void MyArray<T>::popBack() {
	if (this->size == 0) {//大小为0，退出
		return;
	}
	this->size--;
}

//获取数组容量
template<class T>
int  MyArray<T>::getCapacity() {
	return this->capacity;
}

//获取数组大小
template<class T>
int MyArray<T>::getSize() {
	return this->size;
}

//析构函数
template<class T>
MyArray<T>::~MyArray() {
	if (this->address != NULL) {//存有数据-堆
		delete[] this->address;
		this->address = NULL;
		this->capacity = 0;
		this->size = 0;
	}
}

//打印数据
void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
//测试自定义数据类型
class Person {
public:
	Person() {}
	Person(std::string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	std::string m_Name;
	int m_Age{};//以将{}初始化器用于任何类型（可以使用等号，也可以不适用），这是一种通用的初始化语法 等价于 ={0}等价于 =0
	//a{10}  等价于a=10;等价于 a={10}
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) {
		std::cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << std::endl;
	}

}
//测试
void test29() {
	//测试内置数据类型
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.pushBack(i);
	}
	std::cout << "array1打印输出：" << std::endl;
	printIntArray(array1);
	std::cout << "array1的大小：" << array1.getSize() << std::endl;
	std::cout << "array1的容量：" << array1.getCapacity() << std::endl;

	std::cout << "--------------------------" << std::endl;

	MyArray<int> array2(array1);//拷贝构造
	array2.popBack();
	std::cout << "array2打印输出：" << std::endl;
	printIntArray(array2);
	std::cout << "array2的大小：" << array2.getSize() << std::endl;
	std::cout << "array2的容量：" << array2.getCapacity() << std::endl;


	//测试自定义数据类型
		//创建数组
	MyArray<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数据
	pArray.pushBack(p1);
	pArray.pushBack(p2);
	pArray.pushBack(p3);
	pArray.pushBack(p4);
	pArray.pushBack(p5);

	printPersonArray(pArray);

	std::cout << "pArray的大小：" << pArray.getSize() << std::endl;
	std::cout << "pArray的容量：" << pArray.getCapacity() << std::endl;

}