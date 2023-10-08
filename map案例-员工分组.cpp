#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#define cehua 0
#define meishu 1
#define yanfa 2
using namespace std;

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

class Worker
{
public:
	string w_name;
	int w_salary;
};
void creatWorker(vector<Worker>&v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.w_name = "员工";
		worker.w_name += nameSeed[i];
		worker.w_salary = rand() % 10001 + 10000;//10000~20000
		v.push_back(worker);
	}
}
void setGroup(vector<Worker>&v, multimap<int,Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int deptId = rand() % 3;
		//key部门编号，value具体员工
		m.insert(make_pair(deptId, *it));
	}
}
void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "------策划组------" << endl;
	multimap<int, Worker>::iterator pos = m.find(cehua);
	int num = m.count(cehua);//统计具体人数
	int index = 0;
	for (; pos != m.end()&&index<num; pos++,index++)
	{
		cout << "姓名：" << pos->second.w_name << " 工资：" << pos->second.w_salary << endl;
	}
	cout << endl;

	cout << "------美术组------" << endl;
	pos = m.find(meishu);
	num = m.count(meishu);
	index = 0;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "姓名：" << pos->second.w_name << " 工资：" << pos->second.w_salary << endl;
	}
	cout << endl;

	cout << "------研发组------" << endl;
	pos = m.find(yanfa);
	num = m.count(yanfa);
	index = 0;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "姓名：" << pos->second.w_name << " 工资：" << pos->second.w_salary << endl;
	}
	cout << endl;
}
int main()
{
	srand(unsigned int(time(NULL)));
	vector<Worker> vWorker;
	creatWorker(vWorker);
	/*for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "姓名为：" << it->w_name << " 工资为：" << it->w_salary << endl;
	}*/
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	showWorkerByGroup(mWorker);
	return 0;
}