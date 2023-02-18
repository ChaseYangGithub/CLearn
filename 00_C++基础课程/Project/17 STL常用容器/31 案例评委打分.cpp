#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
*/

class Person {
public:
	Person(std::string name, int score) {
		this->name = name;
		this->score = score;
	}
public:
	std::string name;//姓名
	int score;//成绩
};

//创建对象
void createPerson(std::vector<Person>& v) {
	std::string str = "ABCDE";
	for (int i = 0; i < 5; i++) {
		std::string name = "选手";
		name += str[i];
		int score = 0;
		Person p(name, score);
		//将创建的对象存储到容器中
		v.push_back(p);
	}
}
//打分
void setScore(std::vector<Person>& v) {
	for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//将评委的成绩放到deque容器中
		std::deque<int> d;
		for (int i = 0; i < v.size(); i++) {
			int score = std::rand() % 41 + 60;//60-100
			d.push_back(score);
		}
		//排序
		std::sort(d.begin(), d.end());
		//去除最高分和最低分
		d.pop_back();
		d.pop_front();
		//取平均分
		int sum = 0;
		for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
			sum += *it;//累加分数
		}
		int avg = sum / d.size();
		//将平均分赋值给选手
		it->score = avg;
	}

}
//显示成绩
void showScore(std::vector<Person>& v) {
	for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "姓名：" << it->name << " 成绩：" << it->score<<std::endl;
	}
}

void test31() {
	//随机种子
	srand((unsigned int)time(NULL));
	//创建选手
	std::vector<Person> v;//存放选手容器
	createPerson(v);
	//打分
	setScore(v);
	//显示最后得分
	showScore(v);
}