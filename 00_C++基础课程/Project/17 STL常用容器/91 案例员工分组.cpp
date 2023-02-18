#include<iostream>
#include<vector>//存放员工数据
#include<map>//存放部门数据
#include<ctime>//随机数
/*
* 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
* 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
* 随机给10名员工分配部门和工资
* 通过multimap进行信息的插入  key(部门编号) value(员工)
* 分部门显示员工信息
*/

#define CEHUA 0;
#define MEISHU 1;
#define YANFA 2;
//员工
class Worker {
public:
	std::string name;//姓名
	int salary{};//工资----{}初始化去除警告
};
//创建员工
void createWorker(std::vector<Worker>& v) {
	std::string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		Worker worker;
		worker.name = "员工";
		worker.name += nameseed[i];
		worker.salary = rand() % 10000 + 10000;//10000-20000
		//员工放入容器
		v.push_back(worker);
	}
}
//员工分组
void selectGroup(std::vector<Worker>& v, std::multimap<int, Worker>& m) {
	for (std::vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		//产生随机部门编号
		int depId = rand() % 3;//0,1,2
		//将员工插入分组中
		//key为部门编号，value为具体分工
		m.insert(std::make_pair(depId, *it));
	}
}

//按照分组显示
void showWorkerByGroup(std::multimap<int, Worker>& m) {
	//策划部门
	std::cout << "策划部门：" << std::endl;
	std::multimap<int, Worker>::iterator pos = m.find(0);
	int count = m.count(0);//统计具体人数
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++){
		std::cout << "姓名：" << pos->second.name << " 工资：" << pos->second.salary << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	//美术部门
	std::cout << "美术部门：" << std::endl;
	pos = m.find(1);
	count = m.count(1);//统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		std::cout << "姓名：" << pos->second.name << " 工资：" << pos->second.salary << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	//研发部门
	std::cout << "研发部门：" << std::endl;
	pos = m.find(2);
	count = m.count(2);//统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {
		std::cout << "姓名：" << pos->second.name << " 工资：" << pos->second.salary << std::endl;
	}
}

void test91() {
	//创建员工
	std::vector<Worker> worker;
	createWorker(worker);
	//员工分组
	std::multimap<int, Worker> sw;
	selectGroup(worker, sw);
	//分组显示员工
	showWorkerByGroup(sw);
}

