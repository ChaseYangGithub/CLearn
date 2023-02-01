#include<iostream>
using namespace std;
//虚析构语法：
//virtual ~类名() {}
//纯虚析构语法：
//virtual ~类名() = 0; 
//类名::~类名() {}


class Animal {
public:
	Animal() {
		cout << "Animal构造函数调用" << endl;
	}
	virtual void speak() = 0;

	//析构函数加上virtual关键字，变成虚析构函数
	//virtual ~Animal()
	//{
	//	cout << "Animal虚析构函数调用！" << endl;


	virtual ~Animal() = 0;
};
//纯虚析构实现，必须要有
Animal::~Animal() {
	cout << "Animal纯析构函数调用！" << endl;
}
//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
class Cat : public Animal {
public:
	Cat(string name){
		cout << "Cat构造函数调用！" << endl;
		m_Name = new string(name);
	}
	virtual void speak(){
		cout << *m_Name << "小猫在说话!" << endl;
	}
	~Cat(){
		cout << "Cat析构函数调用!" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}
public:
	string* m_Name;
};

void test75()
{
	Animal* animal = new Cat("Tom");
	animal->speak(); 
	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
}

