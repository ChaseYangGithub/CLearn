#include<iostream>
#include<typeinfo>
template<class T>
class Base {
	T t;
};

//�����������ģ�壬������Ҫָ����������T����������

//argument list for class template "Base" is missing
//class Son :public Base;//C++��������Ҫ����������ڴ棬����֪�������е�T���Ͳſ������¼̳�

	
class Son :public Base<int> {//����ָ��һ����������

};

//��������ʹ�ø����е�T���ͣ�����ҲѧҪ�����ģ��
template<class T1,class T2>
class Son2 :public Base<T2> {
public:
	Son2() {
		std::cout << typeid(T1).name() << std::endl;
		std::cout << typeid(T2).name() << std::endl;
	}
};


void test25() {
	Son c;

	Son2<int, char> child1;
}