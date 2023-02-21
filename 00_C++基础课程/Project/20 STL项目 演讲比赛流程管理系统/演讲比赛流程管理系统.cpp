#include<iostream>
#include "speechManager.h"	//演讲管理类


int main() {
	SpeechManager sm;
	//sm.show_Menu();//显示菜单测试
	//sm.printSpeaker();//打印选手数据测试
	int choice = 0;//存储用户功能选择
	while (true) {//循环显示菜单
		sm.show_Menu();//展示菜单
		std::cout << "请输入您的选择：";
		std::cin >> choice;
		switch (choice) {
		case 0:	//退出程序
			sm.exitSystem();
			break;
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看记录
			sm.showRecord();
			break;
		case 3://清空记录
			sm.clearRecord();
			break;
		default:
			system("cls");//未选择功能，清屏重来
			break;
		}
	}


	system("pause");
	return 0;
}

/*
* 学校举行一场演讲比赛，共有12个人参加。比赛共两轮，第一轮为淘汰赛，第二轮为决赛。
* 比赛方式：**分组比赛，每组6个人；选手每次要随机分组，进行比赛
* 每名选手都有对应的编号，如 10001 ~ 10012
* 第一轮分为两个小组，每组6个人。 整体按照选手编号进行**抽签**后顺序演讲。
* 当小组演讲完后，淘汰组内排名最后的三个选手，**前三名晋级**，进入下一轮的比赛。
* 第二轮为决赛，前三名胜出
* 每轮比赛过后需要**显示晋级选手的信息**
*
* 功能：
* 开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
* 查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
* 清空比赛记录：将文件中数据清空
* 退出比赛程序：可以退出当前程序
*/