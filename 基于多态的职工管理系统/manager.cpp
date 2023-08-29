#define _CRT_SECURE_NO_WARNINGS 1
#include "manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
void Manager::showInfo()
{
	cout << "职工编号：" << m_Id
		<< "\t职工姓名：" << m_Name
		<< "\t岗位：" << getDeptName()
		<< "\t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}
string Manager::getDeptName()
{
	return string("经理");
}