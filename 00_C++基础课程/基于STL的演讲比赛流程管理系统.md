* 文件基本上是黑马程序员的文档，部分添加自己需要的内容，仅用于自己学习！
* 链接：[黑马程序视频课程](https://www.bilibili.com/video/BV1et411b73Z?p=167&vd_source=54d6f5e269c668b7d2e2c71481a13789)
* `GitHub`:[链接](https://github.com/ChaseYangGithub/CLearn)

# 演讲比赛流程管理系统

## 1、 演讲比赛程序需求

![1548154762048](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227466.png)



### 1.1 比赛规则

* 学校举行一场演讲比赛，共有**12个人**参加。**比赛共两轮**，第一轮为淘汰赛，第二轮为决赛。
* 比赛方式：**分组比赛，每组6个人**；选手每次要随机分组，进行比赛
* 每名选手都有对应的**编号**，如 10001 ~ 10012 
* 第一轮分为两个小组，每组6个人。 整体按照选手编号进行**抽签**后顺序演讲。
* 当小组演讲完后，淘汰组内排名最后的三个选手，**前三名晋级**，进入下一轮的比赛。
* 第二轮为决赛，**前三名胜出**
* 每轮比赛过后需要**显示晋级选手的信息**

### 1.2 程序功能

* 开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
* 查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
* 清空比赛记录：将文件中数据清空
* 退出比赛程序：可以退出当前程序

## 2、 项目创建

略





## 3、 创建管理类

**功能描述：**

- 提供菜单界面与用户交互
- 对演讲比赛流程进行控制
- 与文件的读写交互




### 3.1创建文件

* 在头文件和源文件的文件夹下分别创建`speechManager.h` 和` speechManager.cpp`文件



### 3.2 头文件实现

在`speechManager.h`中设计管理类

代码如下：

```c++
#ifndef SPEECHMANAGER
#define SPEECHMANAGER

//演讲管理类
class SpeechManager {
public:
	//演讲管理类 构造函数
	SpeechManager();
	//:
	//演讲管理类 析构函数
	~SpeechManager();
};
#endif
```

### 3.3 源文件实现

在`speechManager.cpp`中将构造和析构函数空实现补全

```c++
#include "speechManager.h"
#include<iostream>
//演讲管理类 构造函数
SpeechManager::SpeechManager() {

}
//演讲管理类析构函数
SpeechManager::~SpeechManager() {

}
```

* 至此演讲管理类以创建完毕



## 4、 菜单功能

功能描述：与用户的沟通界面

### 4.1 添加成员函数

在管理类`speechManager.h`中添加成员函数  `void show_Menu();`

![1548123942072](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227467.png)

 



### 4.2 菜单功能实现

* 在管理类`speechManager.cpp`中实现 show_Menu()函数

```c++
//展示功能
void SpeechManager::show_Menu() {
	std::cout << "********************************************" << std::endl;
	std::cout << "*************  欢迎参加演讲比赛 ************" << std::endl;
	std::cout << "*************  1.开始演讲比赛  *************" << std::endl;
	std::cout << "*************  2.查看往届记录  *************" << std::endl;
	std::cout << "*************  3.清空比赛记录  *************" << std::endl;
	std::cout << "*************  0.退出比赛程序  *************" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << std::endl;
}
```



### 4.3 测试菜单功能

* 在`演讲比赛流程管理系统.cpp`中测试菜单功能

代码：

```c++
#include<iostream>
#include "speechManager.h"	//演讲管理类

int main() {
	SpeechManager sm;
	sm.show_Menu();//显示菜单测试



	system("pause");
	return 0;
}
```

* 菜单界面搭建完毕



## 5、 退出功能

### 5.1  提供功能接口

* 在main函数中提供分支选择，提供每个功能接口

代码：

```c++
#include<iostream>
#include "speechManager.h"	//演讲管理类


int main() {
	SpeechManager sm;
	//sm.show_Menu();//显示菜单测试
	int choice = 0;//存储用户功能选择、
	while (true) {//循环显示菜单
		sm.show_Menu();//展示菜单
		std::cout << "请输入您的选择：" ;
		std::cin >> choice;
		switch (choice) {
		case 0:	//退出程序
			break;
		case 1://开始比赛
			break;
		case 2://查看记录
			break;
		case 3://清空记录
			break;
		default:
			system("cls");//未选择功能，清屏重来
			break;
		}
	}


	system("pause");
	return 0;
}

```



### 5.2 实现退出功能

在`speechManager.h`中提供退出系统的成员函数 `	void exitSystem();`

在`speechManager.cpp`中提供具体的功能实现

```c++
//退出程序
void SpeechManager::exitSystem() {
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);//清空I/O缓冲区后退出进程
}
```



### 5.3测试功能

在main函数分支 0  选项中，调用退出程序的接口

![1548124853576](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227468.png)







## 6、演讲比赛功能

### 6.1 功能分析

比赛流程分析：

抽签 → 开始演讲比赛 → 显示第一轮比赛结果 → 

抽签 → 开始演讲比赛 → 显示前三名结果 → 保存分数



### 6.2 创建选手类

* 选手类中的属性包含：选手姓名、分数
* 头文件中创建 `speaker.h`文件，并添加代码：

```C++
#ifndef SPEAKER
#define SPEAKER
//演讲人员类
class Speaker {
public:
	std::string name;//姓名
	double score[2];//分数 ，最多有两轮得分
};


#endif
```



### 6.3 比赛

#### 6.3.1 成员属性添加

* 在`speechManager.h`中添加属性

```C++
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


};
#endif
```





#### 6.3.2 初始化属性

- 在`speechManager.h`中提供开始比赛的的成员函数 `void initSpeech();`

```c++
	//初始化属性
	void initSpeech();
```



- 在`speechManager.cpp`中实现`void initSpeech();`

```c++
//初始化属性
void SpeechManager::initSpeech() {
	//保证所有容器为空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->speaker.clear();
	//初始化比赛轮数
	this->index = 1;
}
```



- `SpeechManager`构造函数中调用`void initSpeech();`

```c++
SpeechManager::SpeechManager()
{
	//初始化属性
	this->initSpeech();
}
```





#### 6.3.3 创建选手

* 在`speechManager.h`中提供开始比赛的的成员函数 `void createSpeaker();`

```C++
	//初始化创建12名选手
	void createSpeaker();
```



* 在`speechManager.cpp`中实现`void createSpeaker();`

```C++
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
```



* `SpeechManager`类的 构造函数中调用`void createSpeaker();`

```C++
SpeechManager::SpeechManager()
{
    //初始化属性
	this->initSpeech();
    
	//创建选手
	this->createSpeaker();
}
```



* 测试 在main函数中，本人创建了成员函数`void printSpeaker()`

```C++
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
```



* 测试完毕后，可以将测试代码删除或注释。





#### 6.3.4 开始比赛成员函数添加

* 在`speechManager.h`中提供开始比赛的的成员函数 `void startSpeech();`
* 该函数功能是主要控制比赛的流程

```C++
	//开始比赛 - 比赛流程控制
	void startSpeech();
```



* 在`speechManager.cpp`中将`startSpeech`的空实现先写入
* 我们可以先将整个比赛的流程 写到函数中

```C++
//开始比赛
void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1、抽签
	
	//2、比赛

	//3、显示晋级结果

	//第二轮比赛

	//1、抽签

	//2、比赛

	//3、显示最终结果

	//4、保存分数
}

```



#### 6.3.5 抽签

**功能描述：**

* 正式比赛前，所有选手的比赛顺序需要打乱，我们只需要将存放选手编号的容器  打乱次序即可



* 在`speechManager.h`中提供抽签的的成员函数 `void speechDraw();`

```C++
	//抽签
	void speechDraw();
```

```C++
//打印通用整型数据
void SpeechManager::printInt(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
```



- 在`speechManager.cpp`中实现成员函数 `void speechDraw();`

```C++
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
```



* 在startSpeech比赛流程控制的函数中，调用抽签函数

* 在main函数中，分支1选项中，调用开始比赛的接口



#### 6.3.6 开始比赛

* `在speechManager.h`中提供比赛的的成员函数 `void speechContest();`

```C++
	//比赛
	void speechContest();
```



* 在`speechManager.cpp`中实现成员函数 `void speechContest();`

```C++
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
```



* 在`startSpeech`比赛流程控制的函数中，调用比赛函数

* 再次运行代码，测试比赛



#### 6.3.7 显示比赛分数

* 在`speechManager.h`中提供比赛的的成员函数 `void showScore();`

```C++
	//显示比赛结果
	void showScore();
```



* 在`speechManager.cpp`中实现成员函数 `void  showScore();`

```C++
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
```

* 在`startSpeech`比赛流程控制的函数中，调用显示比赛分数函数

![1548146903960](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227469.png)





#### 6.3.8 第二轮比赛

第二轮比赛流程同第一轮，只是比赛的轮是+1，其余流程不变

* 在`startSpeech`比赛流程控制的函数中，加入第二轮的流程

![1548148593215](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227470.png)





### 6.4 保存分数

**功能描述：**

* 将每次演讲比赛的得分记录到文件中

**功能实现：**

* 在`speechManager.h`中添加保存记录的成员函数 `void saveRecord();`

```C++
	//保存记录
	void saveRecord();
```



* 在`speechManager.cpp`中实现成员函数 `void saveRecord();`

```C++
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

}
```



* 在`startSpeech`比赛流程控制的函数中，最后调用保存记录分数函数

![1548149937860](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227471.png)



* 测试，整个比赛完毕后记录保存情况

利用记事本打开文件 score.csv，里面保存了前三名选手的编号以及得分

![1548150047975](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227472.png)



至此，整个演讲比赛功能制作完毕！



## 7、 查看记录

### 7.1 读取记录分数



* 在`speechManager.h`中添加保存记录的成员函数 `void loadRecord();`
* 添加判断文件是否为空的标志  `bool fileIsEmpty;`
* 添加往届记录的容器`map<int, vector<string>> m_Record;`   

其中m_Record 中的key代表第几届，value记录具体的信息

```C++
	//读取记录
	void loadRecord();

	//文件为空的标志
	bool fileIsEmpty;

	//往届记录
	map<int, vector<string>> m_Record;
```



* 在`speechManager.cpp`中实现成员函数 `void loadRecord();`

```C++
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
		std::cout << data << std::endl;
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
```



* 在`SpeechManager`构造函数中调用获取往届记录函数

![1548151977242](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227474.png)



### 7.2 查看记录功能

* 在`speechManager.h`中添加保存记录的成员函数 `void showRecord();`

```C++
	//显示往届得分
	void showRecord();
```



* 在`speechManager.cpp`中实现成员函数 `void showRecord();`

```C++
//显示往届得分
void SpeechManager::showRecord() {
	for (int i = 0; i < this->record.size(); i++){//因为数据是交替显示的
		std::cout << "第" << i + 1 << "届 " <<
			"冠军编号：" << this->record[i][0] << " 得分：" << this->record[i][1] << " "
			"\t\t亚军编号：" << this->record[i][2] << " 得分：" << this->record[i][3] << " "
			"\t\t季军编号：" << this->record[i][4] << " 得分：" << this->record[i][5] << std::endl;
	}
	system("pause");
	system("cls");
}
```



### 7.3 测试功能

在main函数分支 2  选项中，调用查看记录的接口

![1548152359604](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227475.png)





### 7.4 bug解决

目前程序中有几处bug未解决：

1. 查看往届记录，若文件不存在或为空，并未提示

解决方式：在showRecord函数中，开始判断文件状态并加以判断

![1548152803116](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227476.png)



2. 若记录为空或不存在，比完赛后依然提示记录为空

解决方式：`saveRecord`中更新文件为空的标志

![1548153005042](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227477.png)

3. 比完赛后查不到本届比赛的记录，没有实时更新

解决方式：比赛完毕后，所有数据重置

![1548153319587](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227478.png)



4. 在初始化时，没有初始化记录容器

解决方式：`initSpeech`中添加 初始化记录容器

![1548154340974](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227479.png)

5. 每次记录都是一样的

解决方式：在main函数一开始 添加随机数种子

```C++
srand((unsigned int)time(NULL));
```





## 8、 清空记录

### 8.1 清空记录功能实现

* 在`speechManager.h`中添加保存记录的成员函数 `void clearRecord();`

```C++
	//清空记录
	void clearRecord();
```



* 在`speechManager.cpp`中实现成员函数 `void clearRecord();`

```C++
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
```

### 8.2 测试清空

在main函数分支 3  选项中，调用清空比赛记录的接口

![1548154674242](https://cdn.jsdelivr.net/gh/ChaseYangGithub/MyBlogResource@main/MD/202302211227480.png)

运行程序，测试清空记录

`speech.csv`中记录也为空

* 至此本案例结束！ `^_^`

