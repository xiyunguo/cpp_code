#define _CRT_SECURE_NO_WARNINGS 1
#include "employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
void Employee::showInfo()
{
	cout << "ְ����ţ�" << m_Id
		<< "\tְ��������" << m_Name
		<< "\t��λ��" << getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}
string Employee::getDeptName()
{
	return string("Ա��");
}