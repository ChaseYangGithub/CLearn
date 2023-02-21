#include "speechManager.h"
#include<iostream>
#include<algorithm>//算法
#include<ctime>//随机数
#include<deque>//双端队列
#include<numeric>//算数生成算法
#include<fstream>//文件读写
//演讲管理类 构造函数
SpeechManager::SpeechManager() {
	//初始化属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();
	//获取往届记录
	this->loadRecord();
}
//演讲管理类析构函数
SpeechManager::~SpeechManager() {

}
//展示功能
void SpeechManager::show_Menu() {
	std::cout << "********************************************" << std::endl;
	std::cout << "*************  欢迎参加演讲比赛 ************" << std::endl;
	std::cout << "*************  1.开始演讲比赛  *************" << std::endl;
	std::cout << "*************  2.查看往届记录  *************" << std::endl;
	std::cout << "*************  3.清空比赛记录  *************" << std::endl;
	std::cout << "*************  0.退出比赛程序  *************" << std::endl;
	std::cout << "********************************************" << std::endl;
	//std::cout << "请选择功能：" << std::endl;
	std::cout << std::endl;
}
//退出程序
void SpeechManager::exitSystem() {
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);//清空I/O缓冲区后退出进程
}
//初始化属性
void SpeechManager::initSpeech() {
	//保证所有容器为空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->speaker.clear();
	//初始化比赛轮数
	this->index = 1;
	//初始化记录容器
	this->record.clear();
}
//初始化创建12名选手
void SpeechManager::createSpeaker() {
	std::string nameSeed = "abcdefghijkl";
	for (int i = 0; i < nameSeed.size(); i++) {
		//初始化姓名
		std::string name = "选手";
		name += nameSeed[i];
		Speaker s;
		s.name = name;
		//初始化所有成绩为0
		for (int i = 0; i < 2; i++) {
			s.score[i] = 0;
		}
		//选手编号
		this->v1.push_back(i + 10001);//对应编号
		//选手编号及选手信息关系
		this->speaker.insert(std::make_pair(i + 10001, s));
	}
}
//测试 打印所有选手信息
void SpeechManager::printSpeaker(){
	for (std::map<int, Speaker>::iterator it = this->speaker.begin(); it != this->speaker.end(); it++) {
		std::cout << "选手编号：" << it->first
			<< "  姓名：" << it->second.name
			<< "  成绩1：" << it->second.score[0]
			<< "  成绩2：" << it->second.score[1] << std::endl;
	}
	std::cout << std::endl;
}
//打印通用整型数据
void SpeechManager::printInt(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
//抽签
void SpeechManager::startDraw() {
	std::cout << "第" << this->index << "轮比赛--选手正在抽签" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "抽签后演讲顺序如下：" << std::endl;
	std::srand((unsigned int)time(NULL));//保证每次随机数不同
	if (this->index == 1) {//第一轮比赛
		std::random_shuffle(v1.begin(), v1.end());//打乱默认排序
		this->printInt(v1);//打印抽签顺序
	}
	else {//第二轮比赛
		std::random_shuffle(v2.begin(), v2.end());//打乱默认排序
		this->printInt(v2);//打印抽签顺序
	}
	std::cout << "-----------------------------------------------------------------------" << std::endl;
}
//比赛中
void SpeechManager::speechContest() {
	std::cout << "第" << this->index << "轮比赛--正在进行" << std::endl;
	std::multimap<double, int,std::greater<int>> groupScore;//用于打印小组数据  存放选手成绩 选手编号
	std::vector<int> src;//比赛人员容器
	int num=0;//记录人员数字，用于判断分组
	//判断当前比赛轮次
	if (this->index == 1) {
		src = v1;
	}
	else {
		src = v2;
	}
	//参赛选手评分
	for (std::vector<int>::iterator it = src.begin(); it != src.end(); it++) {
		num++;
		//评委打分
		std::deque<double> d;//双端队列，易于添加删除头部尾部数据
		double score;
		for (int i = 0; i < 10; i++) {
			score = (rand() % 401 + 600) / 10.f;//总分600-1000 
			d.push_back(score);
		}
		std::sort(d.begin(), d.end(), std::greater<double>());//排序
		d.pop_back();//去掉最低分
		d.pop_front();//去掉最高分
		//总分
		double sum = std::accumulate(d.begin(), d.end(), 0.0f);//获取总分 加上0.0确保为浮点数
		//平均分
		double avg = sum / (double)d.size();
		//保存分数
		this->speaker[*it].score[this->index - 1] = avg;
		//保存分数到临时容器 按6人一组
		groupScore.insert(std::make_pair(avg, *it));
		if (num % 6 == 0) {//输出成绩 保留前三
			std::cout << "第" << num / 6 << "小组比赛名次：" << std::endl;
			//输出成绩
			for (std::multimap<double, int, std::greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++){
				std::cout << "编号: " << it->second 
					<< " 姓名： " << this->speaker[it->second].name 
					<< " 成绩： " << this->speaker[it->second].score[this->index - 1] << std::endl;
			}

			int count = 0;
			//取前三名
			for (std::multimap<double, int, std::greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++){
				if (this->index == 1){
					v2.push_back((*it).second);
				}
				else{
					v3.push_back((*it).second);
				}
			}
			groupScore.clear();//清理临时容器
			std::cout << std::endl;
		}
	}
	std::cout << "------------- 第" << this->index << "轮比赛完毕  ------------- " << std::endl;
}
//显示比赛分数--晋级情况
void SpeechManager::showScore() {
	std::cout << "第" << this->index << "轮晋级选手信息如下：" << std::endl;
	std::vector<int> v;
	if (this->index == 1) {//确认晋级名单
		v = v2;
	}
	else {
		v = v3;
	}
	//打印晋级选手信息
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "选手编号：" << *it
			<< " 姓名：" << speaker[*it].name
			<< " 得分：" << speaker[*it].score[this->index - 1]
			<< std::endl;
	}
	system("pause");
	system("cls");

}
//保存数据到本地
void SpeechManager::saveRecord() {
	std::ofstream ofs;
	ofs.open("score.csv", std::ios::out|std::ios::app);//写文件，追加方式 相关知识点：C++核心 文件操作
	//将数据写入文件中
	for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {//csv ,格式
		ofs << *it << ","
			<< speaker[*it].score[1] << ",";
	}
	ofs<<std::endl;
	//关闭文件
	ofs.close();
	std::cout << "记录已经保存" << std::endl;
	this->fileIsEmpty = false;//有文件了

}
//开始比赛
void SpeechManager::startSpeech() {
	//第一轮比赛
	system("cls");
	//抽签
	startDraw();
	//比赛
	speechContest();
	//显示结果
	showScore();
	//第二轮比赛
	this->index++;
	//抽签
	startDraw();
	//比赛
	speechContest();
	//显示结果
	showScore();
	//保存分数
	saveRecord();
	//比赛完成重置数据
	//初始化属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();
	//获取往届记录
	this->loadRecord();
	std::cout << "本届已结束" << std::endl;
	system("pause");
	system("cls");
}
//读取本地记录
void SpeechManager::loadRecord() {
	std::ifstream ifs("score.csv", std::ios::in);//输入流对象 读取文件
	//文件不存在情况
	if (!ifs.is_open()) {//判断文件是否存在
		std::cout << "文件不存在" << std::endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在为空情况
	char ch;
	ifs >> ch;
	if (ifs.eof()) {//文件读取结束
		std::cout << "文件为空" << std::endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);//读取单个字符放回去
	//读取字符
	std::string data;
	int num = 0;//数据编号
	while (ifs >> data) {//读完一行数据返回假的标志
		//std::cout << data << std::endl;
		std::vector < std::string> v;
		int pos = -1;//记录 ，位置
		int start = 0;//记录当前数据位置
		while (true) {
			pos=data.find(",", start);//从0开始查找","
			if (pos == -1) {
				break;//找不到
			}
			std::string tmp = data.substr(start, pos - start);//找到了进行分割 参数1 起始位置 参数2截取长度
			v.push_back(tmp);//存储数据
			start = pos + 1;//分隔符后
		}
		this->record.insert(std::make_pair(num, v));
		num++;
	}
	ifs.close();
}
//显示往届得分
void SpeechManager::showRecord() {
	if (this->fileIsEmpty) {
		std::cout << "文件不存在或者为空" << std::endl;
	}
	else {
		for (int i = 0; i < this->record.size(); i++) {//因为数据是交替显示的
			std::cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->record[i][0] << " 得分：" << this->record[i][1] << " "
				"\t\t亚军编号：" << this->record[i][2] << " 得分：" << this->record[i][3] << " "
				"\t\t季军编号：" << this->record[i][4] << " 得分：" << this->record[i][5] << std::endl;
		}
	}
	system("pause");
	system("cls");
}
//清空记录
void SpeechManager::clearRecord() {
	int select = 0;
	while (select!=1&&select!=2) {//非0为真
		std::cout << "确认清空？" << std::endl
			<< "1 确认" << std::endl
			<< "2 取消" << std::endl
			<< "你的选择：";
		std::cin >> select;
		system("cls");
	}
	if (select == 1) {
		//打开模式ios::trunc如果存在删除并重新创建
		std::ofstream ofs("score.csv", std::ios::trunc);
		ofs.close();
		//初始化属性
		this->initSpeech();
		//创建选手
		this->createSpeaker();
		//获取往届记录
		this->loadRecord();
		std::cout << "清空成功！" << std::endl;
		system("pause");
		system("cls");
	}
	else if (select == 2) {
		return;
	}
	
}