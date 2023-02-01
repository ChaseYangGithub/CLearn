#include<iostream>
#include<fstream>	//包含文件流
using namespace std;
//文本文件写文件

//文本文件写文件操作
void fileWriter() {
	//创建对象流
	ofstream ofs;
	//打开文件
	ofs.open("text.txt",ios::out );//为写文件而打开文件  文件目录为当前程序所在目录下的text.txt文件
	//写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	//关闭文件
	ofs.close();
}