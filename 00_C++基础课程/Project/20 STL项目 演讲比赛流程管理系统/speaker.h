#ifndef SPEAKER
#define SPEAKER
#include<iostream>
//演讲人员类
class Speaker {
public:
	Speaker();//防止初始化警告问题
public:
	std::string name;//姓名
	double score[2];//分数 ，最多有两轮得分
};


#endif