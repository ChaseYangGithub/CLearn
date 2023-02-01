#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//文件读取操作
void fileRead() {
	//创建流对象
	ifstream ifs;
	//打开文件判断文件是否存在
	ifs.open("text.txt",ios::in ); //为读文件而打开文件
	if (!ifs.is_open()) {//判断文件是否打开成功
		cout << "文件打开失败" << endl;
		return;
	}
	//四种输出方式
	//第一种
	
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {//读完一行数据返回假的标志
	//	cout << buf << endl;
	//}
	
	//第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))) {//获取行数据 读取数据的指针，最大读取数据的数目长度
	//	cout << buf << endl;
	//}

	//第三种
	//string buf;
	//while (getline(ifs,buf)) {//包含在string内，如果直接使用std命名空间显示缺失，可能是版本问题，同样的第二种方法中的可用
	//	cout << buf <<endl;
	//}
	
	//第四种--不推荐用
	char c;
	while ((c = ifs.get()) != EOF) {//每次读取一个字符 EOF: end of file
		cout << c;
	}
	//关闭文件
	ifs.close();
}
