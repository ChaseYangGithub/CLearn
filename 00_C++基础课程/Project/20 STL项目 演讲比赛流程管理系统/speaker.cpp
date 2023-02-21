#include<iostream>
#include "speaker.h"
Speaker::Speaker() {
	this->score[0] =(double)1.0;//强制转换防止类型转化警告
	this->score[1] = (double)1.0;
}