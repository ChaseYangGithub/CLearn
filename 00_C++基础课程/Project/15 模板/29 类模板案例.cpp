#include<iostream>
#include "myArray.h"

//���캯��
template<class T>
MyArray<T>::MyArray(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->address = new T[this->capacity];//�����û����ݴ�����ʼ�ռ�
}

//�������캯��
template<class T>
MyArray<T>::MyArray(const MyArray& arr) {
	this->capacity = arr.capacity;
	this->size = arr.size;
	this->address = new T[this->capacity];//�����¿ռ�
	for (int i = 0; i < this->size; i++) {//��������
		//���TΪ���󣬶��һ�����ָ�룬������Ҫ���� = ����������Ϊ����ȺŲ��� ���� ���Ǹ�ֵ��
		// ��ͨ���Ϳ���ֱ��= ����ָ��������Ҫ���
		if (i < this->capacity - 1) {
			this->address[i] = arr.address[i];

		}
	}
}



//����=������ ��ֹǳ��������
template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray& arr) {//�˴�ע��Ҫȷ��MyArray�����������ͣ����Է���ֵ��<T> �����ܱ�����׼ȷ
	if (this->address != NULL) {//�����ռ䲻Ϊ��
		delete[] this->address;
		this->capacity = 0;
		this->size = 0;
	}
	this->capacity = arr.capacity;
	this->size = arr.size;
	this->address = new T[this->capacity];//�����¿ռ�
	for (int i = 0; i < this->size; i++) {//��������
		this->address[i] = arr.address[i];
	}
	return *this;
}

//����[]ʵ��ͨ���±��������
template<class T>
T& MyArray<T>::operator[](int index) {
	if (this->size <= index) {
		std::cout << "Խ��" << std::endl;
	}
	return this->address[index];
}

//β�巨
template<class T>
void MyArray<T>::pushBack(const T&t) {
	if (this->capacity == this->size) {//�ռ���
		return;
	}
	this->address[this->size] = t;
	this->size++;
}

//βɾ��
template<class T>
void MyArray<T>::popBack() {
	if (this->size == 0) {//��СΪ0���˳�
		return;
	}
	this->size--;
}

//��ȡ��������
template<class T>
int  MyArray<T>::getCapacity() {
	return this->capacity;
}

//��ȡ�����С
template<class T>
int MyArray<T>::getSize() {
	return this->size;
}

//��������
template<class T>
MyArray<T>::~MyArray() {
	if (this->address != NULL) {//��������-��
		delete[] this->address;
		this->address = NULL;
		this->capacity = 0;
		this->size = 0;
	}
}

//��ӡ����
void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
//�����Զ�����������
class Person {
public:
	Person() {}
	Person(std::string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	std::string m_Name;
	int m_Age{};//�Խ�{}��ʼ���������κ����ͣ�����ʹ�õȺţ�Ҳ���Բ����ã�������һ��ͨ�õĳ�ʼ���﷨ �ȼ��� ={0}�ȼ��� =0
	//a{10}  �ȼ���a=10;�ȼ��� a={10}
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) {
		std::cout << "������" << personArr[i].m_Name << " ���䣺 " << personArr[i].m_Age << std::endl;
	}

}
//����
void test29() {
	//����������������
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.pushBack(i);
	}
	std::cout << "array1��ӡ�����" << std::endl;
	printIntArray(array1);
	std::cout << "array1�Ĵ�С��" << array1.getSize() << std::endl;
	std::cout << "array1��������" << array1.getCapacity() << std::endl;

	std::cout << "--------------------------" << std::endl;

	MyArray<int> array2(array1);//��������
	array2.popBack();
	std::cout << "array2��ӡ�����" << std::endl;
	printIntArray(array2);
	std::cout << "array2�Ĵ�С��" << array2.getSize() << std::endl;
	std::cout << "array2��������" << array2.getCapacity() << std::endl;


	//�����Զ�����������
		//��������
	MyArray<Person> pArray(10);
	Person p1("�����", 30);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);

	//��������
	pArray.pushBack(p1);
	pArray.pushBack(p2);
	pArray.pushBack(p3);
	pArray.pushBack(p4);
	pArray.pushBack(p5);

	printPersonArray(pArray);

	std::cout << "pArray�Ĵ�С��" << pArray.getSize() << std::endl;
	std::cout << "pArray��������" << pArray.getCapacity() << std::endl;

}