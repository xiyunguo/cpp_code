#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

//员工类
class Employee :public Worker
{
public:
	//构造函数
	Employee(int id, string name, int did);
	//显示个人信息
	virtual void showInfo();
	//获取职工岗位名称
	virtual string getDeptName();
};