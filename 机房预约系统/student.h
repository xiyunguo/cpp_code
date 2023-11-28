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
	student();//Ĭ�Ϲ���
	student(int id, string name, string pwd);//�вι���
	virtual void operMenu();//�˵�����

	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();

	int m_Id;//ѧ��

	//��������
	vector<ComputerRoom> vCom;


};
