#include<iostream>
using namespace std;

//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问 儿子可以访问父亲的保护内容
//私有权限  private    类内可以访问  类外不可以访问 儿子不可以访问父亲的私有内容

class Person {
	//姓名公共权限
public:
	string name;
	//汽车保护权限
protected:
	string car;
	//银行卡密码 私有权限
private:
	int password;
public:
	void func() {
		name = "张三";
		car = "拖拉机";
		password = 123456;
	}
};

//权限控制
void accessControl() {
	Person p;
	p.name = "李四";
	//p.car = "Benz";	//保护权限外类访问不到
	//p.password = 123;	//私有权限外类访问不到
}