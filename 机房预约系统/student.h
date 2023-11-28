#pragma once
#include <iostream>
#include "identity.h"
#include <fstream>
#include <vector>
#include <string>
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"
using namespace std;

class student :public identity
{
public:
	student();//默认构造
	student(int id, string name, string pwd);//有参构造
	virtual void operMenu();//菜单界面

	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();

	int m_Id;//学号

	//机房容器
	vector<ComputerRoom> vCom;


};
