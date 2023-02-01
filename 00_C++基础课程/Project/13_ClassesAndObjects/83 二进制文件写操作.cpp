#include<iostream>
#include<fstream>
using namespace std;
//二进制文件写操作

class Append {
public:
	//注意使用二进制读写时类型大小要一致
	char name[64];	//文件最好使用字符而不是字符串，因为C++的文件用C写的
	int age;
};

//二进制文件写操作
void binaryWriter() {
	//创建输出流对象
	ofstream ofs("person.txt", ios::out | ios::binary);//写文件 二进制方式
	//打开文件
	//ofs.open("person.txt", ios::out | ios::binary);//和上方等价
	Append a = { "张三",13};
	//写文件
	ofs.write((const char*)&a, sizeof(a));//使用的数据指针，大小
	//关闭文件
	ofs.close();

}