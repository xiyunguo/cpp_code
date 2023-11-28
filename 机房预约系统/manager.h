#pragma once
#include <iostream>
#include "identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"
using namespace std;
class manager :public identity
{
public:
	manager();
	manager(string name, string pwd);
	virtual void operMenu();

	void addPerson();
	void showPerson();
	void showComputer();
	void cleanFile();

	//��ʼ������
	void initVector();
	//ѧ������
	vector<student> vStu;
	//��ʦ����
	vector<teacher> vTea;

	vector<ComputerRoom> vCom;

	bool checkRepeat(int id, int type);

};