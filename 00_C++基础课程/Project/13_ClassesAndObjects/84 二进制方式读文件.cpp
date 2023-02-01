#include<iostream>
#include<fstream>
using namespace std;
//二进制方式读文件

class Base {
public:
	//注意使用二进制读写时类型大小要一致
	char name[64];
	int age;
};

//二进制文件读取操作
void binaryRead() {
	//创建输出流并以二进制的方式读取
	ifstream ifs("person.txt", ios::in | ios::binary);
	//判断是否读取成功
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
	}
	Base b;
	ifs.read((char*)&b, sizeof(b));//read使用二进制方式读取数据
	cout << "姓名：" << b.name << "年龄：" << b.age;
}