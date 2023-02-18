#include<iostream>
#include "27person.h"
/*
* 
问题：类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

注意：对于`VS2022平台` `C+ + 14 ` `WinSDK10`
* **可以实现 * *函数实现在cpp
* **可以实现 * *函数声明实现全放在.h文件中
* **可以实现 * *#include "person.cpp" 单独创建`person.cpp`实现函数实现，实例中包含cpp源文件
* **可以实现 * *将声明和实现写到一起，文件后缀名及cpp文件中引用改为.hpp

*/


//构造函数 类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

//成员函数 类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	std::cout << "姓名: " << this->name << " 年龄:" << this->age << std::endl;
}
void test27() {
	Person<std::string, int> p("张三", 21);
	p.showPerson();	
}