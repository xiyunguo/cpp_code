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
	cout << "ְ����ţ�" << m_Id
		<< "\tְ��������" << m_Name
		<< "\t��λ��" << getDeptName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}
string Boss::getDeptName()
{
	return string("�ϰ�");
}