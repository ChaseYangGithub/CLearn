#include<iostream>
using namespace std;
/*
案例描述：
分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

多态的优点：
* 代码组织结构清晰
* 可读性强
* 利于前期和后期的扩展以及维护

*/
//普通实现
class Calculate {
public:
	int getResult(string op) {
		if (op == "+") {
			return num1 + num2;
		}
		else if (op == "-") {
			return num1 - num2;
		}
		else if (op == "*") {
			return num1 * num2;
		}
		else {
			return -1;
		}
		//如果要提供新的运算，需要修改源码
	}
public:
	int num1;
	int num2;
};
//多态实现
//抽象计算器类
//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
class AbstrateCalculate {
public:
	virtual int getResult() {
		return 0;
	}
public:
	int num1;
	int num2;
};
//加法计算器
class AddCalculate :public AbstrateCalculate {
public:
	int getResult() {
		return num1 + num2;
	}
};
//减法计算器
class SubCalculate :public AbstrateCalculate {
	int getResult() {
		return num1 - num2;
	}
};
//乘法计算器
class MulCalculate :public AbstrateCalculate {
	int getResult() {
		return num1 * num2;
	}
};
void polymorTest() {
	//普通实现测试
	Calculate c;
	c.num1 = 10;
	c.num2 = 10;
	cout << c.num1 << " + " << c.num2 << " = " << c.getResult("+") << endl;
	cout << c.num1 << " - " << c.num2 << " = " << c.getResult("-") << endl;
	cout << c.num1 << " * " << c.num2 << " = " << c.getResult("*") << endl;

	//多态实现测试
	AbstrateCalculate* abc = new AddCalculate();
	abc->num1 = 10;
	abc->num2 = 10;
	cout << abc->num1 << " + " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;//用完销毁
	AbstrateCalculate* a = new SubCalculate();
	a->num1 = 10;
	a->num2 = 10;
	cout << a->num1 << " - " <<a->num2 << " = " << a->getResult() << endl;
	delete a;//用完销毁
	AbstrateCalculate* b = new MulCalculate();
	b->num1 = 10;
	b->num2 = 10;
	cout << b->num1 << " * " << b->num2 << " = " << b->getResult() << endl;
	delete b;//用完销毁
}