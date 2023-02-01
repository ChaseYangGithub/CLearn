#include<iostream>
using namespace std;
//浅拷贝与深拷贝
/*
	浅拷贝：简单的赋值拷贝操作
	// cheight=p.cheight;
	深拷贝：在堆区重新申请空间，进行拷贝操作
	//cheight = new int(*p.cheight);

	如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
*/
class Cat {
public:
	//无参（默认）构造函数
	Cat() {
		cout << "无参构造函数" << endl;
	}
	//有参构造函数
	Cat(int age,int height) {
		cout << "有参构造函数" << endl;
		cage = age;
		cheight = new int(height);
	}
	//拷贝构造函数
	Cat(const Cat& p) {
		cout << "拷贝构造函数" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复性释放堆区问题
		//浅拷贝指针类型复制相同的地址，但是该地址只能释放一次，再次释放则非法报错
		// cheight=p.cheight;
		//深拷贝指针类型在堆区开辟新的空间存储原指针指向的数据并存储对应地址
		//cheight = new int(*p.cheight);
		cage = p.cage;
		cheight = new int(*p.cheight); 
	}
	//析构函数
	~Cat() {
		cout << "析构函数" << endl;
		//析构代码，将堆区开辟的数据进行释放
		if (cheight != NULL) {
			delete cheight;
			cheight = NULL;
		}
	}
public:
	int cage;	//年龄
	int *cheight;//高度
};

//浅拷贝与深拷贝测试
void shallowCopyAndDeepCopy() {
	Cat c1(21,174);
	Cat c2(c1);
	cout << "c1的年龄：" << c1.cage << "身高：" << *c1.cheight << endl;
	cout << "c2的年龄：" << c2.cage << "身高：" << *c2.cheight << endl;
}