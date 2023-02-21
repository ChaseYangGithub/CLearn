#ifndef SPEECHMANAGER
#define SPEECHMANAGER
#include<vector>
#include<map>
#include "speaker.h"
//演讲管理类
class SpeechManager {
public:
	//演讲管理类 构造函数
	SpeechManager();
	//演讲管理类 析构函数
	~SpeechManager();
	//展示菜单
	void show_Menu();
	//退出程序
	void exitSystem();
	//初始化属性
	void initSpeech();
	//初始化创建选手
	void createSpeaker();
	//测试：显示所有选手信息
	void printSpeaker();
	//开始比赛
	void startSpeech();
	//打印通用整型数据 使用 
	void printInt(std::vector<int> &v);
	//抽签
	void startDraw();
	//比赛中
	void speechContest();
	//显示比赛分数--晋级情况
	void showScore();
	//保存数据到本地
	void saveRecord();
	//读取本地记录
	void loadRecord();
	//显示往届得分
	void showRecord();
	//清空记录
	void clearRecord();
public:
	//比赛选手 容器 12人
	std::vector<int> v1;
	//第一轮晋级容器 6人
	std::vector<int> v2;
	//胜利前三名容器 3人
	std::vector<int> v3;
	//存放编号及对应具体选手的容器
	std::map<int, Speaker> speaker;
	//当前比赛轮数
	int index;
	//文件为空标志
	bool fileIsEmpty;
	//往届记录
	std::map<int, std::vector<std::string>> record;

};
#endif