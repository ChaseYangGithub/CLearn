#include<iostream>
using namespace std;
/*
	成员属性设置为私有
	优点：
		将所有成员属性设置为私有，可以自己控制读写权限
		对于写权限，我们可以检测数据的有效性
*/

class Person {
public:
	//姓名设置可读可写
	void setName(string name) {
		uname = name;
	}
	string getName() {
		return uname;
	}
	//获取年龄
	int getAge() {
		return uage;
	}
	//设置年龄
	void setAge(int age) {
		if (age < 0 || age>150) {
			uage = 0;
			cout << "你个老妖精" << endl;
			return;
		}
		uage = age;
	}
	//情人设置可写
	void setLove(string love) {
		ulove = love;
	}
private:
	string uname;//可读可写 姓名
	int uage;//只读  年龄	//如果放在情人前面报错
	string ulove;//只写 情人

	//下方语句在使用Person p;格式构造对象不报错
	//string ulove;//只写 情人
	//int uage;//只读  年龄	//如果放在情人前面报错
	
};

void privateAttribute() {
	
	
	/*
		在使用Person p方式时 报错
		未使用显示的方式new对象导致对象调用malloc,分配内存后未调用构造函数初始化
		原因：
		使用结构体变量类型定义一个结构体时(Type a)，因为工程环境或者其他原因导致编译器对该变量只使用malloc分配内存，
		没有调用相应的构造函数对内部的数据初始化，比如重要的指针数据，和基于指针的容器数据string或其他容器。
		解决方法：
		程序员需要显式的使用new构造对象(Type *a=new Type())，不管是结构体对象还是类对象，也就是用指针代替值对象。

		注意点：
		显式使用了new以后就需要用指针指向该内存，所以在使用对象时，为了避免出现意外的只有malloc没有构造的情况，需要使用指针替代值对象，传值的时候只需要将指针解引用就可以。

	*/
	//Person p;
	Person *p=new Person();
	//姓名设置
	p->setName("张三");
	cout << "姓名：" << p->getName() << endl;
	//年龄设置
	p->setAge(21);
	cout << "年龄：" << p->getAge() << endl;
	//情人设置
	p->setLove("苍井空");
	//cout << "情人：" << p->ulove << endl;//只写属性，不可读取

}
