#define _CRT_SECURE_NO_WARNINGS 1
#include "boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
void Boss::showInfo()
{
	cout << "职工编号：" << m_Id
		<< "\t职工姓名：" << m_Name
		<< "\t岗位：" << getDeptName()
		<< "\t岗位职责：管理公司所有事务" << endl;
}
string Boss::getDeptName()
{
	return string("老板");
}