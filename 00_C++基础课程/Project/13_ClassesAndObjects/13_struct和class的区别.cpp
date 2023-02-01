#include<iostream>
using namespace std;

/*
	在C++中struct和class的唯一区别就在于默认的访问权限不同
	区别：
		struct默认访问权限为公共
		class默认权限为私有
*/

class C1 {
	int a;	//默认是私有权限
};
struct C2 {
	int a;//默认是公共权限
};

void diffInStructAndClass() {
	//C1 c1;
	C2 c2;
	//c1.a = 10;//错误，访问权限是私有
	c2.a = 20;//访问权限是公共
}