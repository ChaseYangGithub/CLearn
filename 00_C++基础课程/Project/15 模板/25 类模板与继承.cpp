#include<iostream>
#include<typeinfo>
template<class T>
class Base {
	T t;
};

//如果父类是类模板，子类需要指定出父类中T的数据类型

//argument list for class template "Base" is missing
//class Son :public Base;//C++编译器需要给子类分配内存，必须知道父类中的T类型才可以向下继承

	
class Son :public Base<int> {//必须指定一个数据类型

};

//如果想灵活使用父类中的T类型，子类也学要变成类模板
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