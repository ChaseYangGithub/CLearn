#include<iostream>
#include<fstream>
#include<map>
#include "order.h"
#include "globalFile.h"

//构造函数
Order::Order() {
	std::string data;//日期
	std::string time;//上下午
	std::string id;//学号
	std::string username;//姓名
	std::string room;//机房
	std::string status;//状态
	std::ifstream ifs;
	std::string key;//键值 用于存储数据到容器
	std::string value;//值 用于存储数据到容器
	std::map<std::string, std::string> m;
	int pos = -1;//用于记录：位置
	this->size = 0;//记录数
	ifs.open(ORDER_FILE, std::ios::in);
	while (ifs >> data && ifs >> time && ifs >> id && ifs >> username && ifs >> room && ifs >> status) {
		//测试代码--测试读取
	/*	std::cout << data << std::endl;
		std::cout << time << std::endl;
		std::cout << id << std::endl;
		std::cout <<username << std::endl;
		std::cout << room << std::endl;
		std::cout << status << std::endl;*/
		m.clear();
		//std::map<std::string, std::string> m;
		//map自带的.clear()函数会清空map里存储的所有内容，但如果map值存储的是指针，则里面的值不会被清空
		
		//日期 中文及中文字符占据两个单位
		//pos = (int)data.find("日");//0
		//pos = (int)data.find("期");//2
		pos = (int)data.find("：");//4--find找的是当前字符开始位置，若想从下一个数据开始要+2（当前中文）
		//如果使用英文:则+1
		//std::cout << pos;
		if (pos != -1) {
			//返回pos开始  长度为n的string
			key = data.substr(0, pos + 2);//备注值 从 下标0开始长度为pos+2个数据
			value = data.substr(pos + 2, data.size() - pos - 1);
		/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//上下午
		pos = (int)time.find("：");//查找冒号锁定数据
		if (pos != -1) {
			//返回pos开始  长度为n的string
			key = time.substr(0, pos + 2);//备注值
			value = time.substr(pos + 2, time.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//学号
		pos = (int)id.find("：");//查找冒号锁定数据
		if (pos != -1) {
			//返回pos开始  长度为n的string
			key = id.substr(0, pos + 2);//备注值
			value = id.substr(pos + 2, id.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//姓名
		pos = (int)username.find("：");//查找冒号锁定数据
		if (pos != -1) {
			//返回pos开始  长度为n的string
			key = username.substr(0, pos + 2);//备注值
			value = username.substr(pos + 2, username.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//机房
		pos = (int)room.find("：");//查找冒号锁定数据
		if (pos != -1) {
			//返回pos开始  长度为n的string
			key = room.substr(0, pos + 2);//备注值
			value = room.substr(pos + 2, room.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//状态
		pos = (int)status.find("：");//查找冒号锁定数据
		if (pos != -1) {
			//返回pos开始  长度为n的string
			key = status.substr(0, pos + 2);//备注值
			value = status.substr(pos + 2, status.size() - pos - 1);
			/*	std::cout << key;
			std::cout << value<<std::endl;*/
			m.insert(std::make_pair(key, value));
		}
		//保存数据到容器
		this->data.insert(std::make_pair(this->size, m));
		this->size++;//预约数量加1
	}
	//更新预约记录测试
	//std::string test = this->data[0]["日期："];//2
	//std::cout << test;
	
	//代码测试--测试文件输出
	//for (std::map<int, std::map<std::string, std::string>>::iterator it = this->data.begin(); it != this->data.end(); it++) {
	//	std::cout << "key:" << it->first << " value:\t";
	//	for (std::map<std::string, std::string>::iterator t = it->second.begin(); t != it->second.end(); t++) {//输出单行内容
	//		std::cout << t->first << " " << t->second << " ";
	//	}
	//	std::cout << std::endl;
	//}
	ifs.close();
}
//更新预约记录
void Order::UpdateOrder() {
	if (this->size == 0) {
		return;//说明没有要更新的数据
	}

	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);//如果存在先删除在创建
	for (int i = 0; i < this->size; i++) {
		ofs << "日期：" << this->data[i]["日期："] << " "; // find element matching _Keyval or insert value-initialized value
		ofs << "代码：" << this->data[i]["代码："] << " ";
		ofs << "学号：" << this->data[i]["学号："] << " ";
		ofs << "姓名：" << this->data[i]["姓名："] << " ";
		ofs << "机房：" << this->data[i]["机房："] << " ";
		ofs << "状态：" << this->data[i]["状态："] << std::endl;
	}
	ofs.close();
}