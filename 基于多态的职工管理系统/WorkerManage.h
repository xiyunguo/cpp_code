#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <fstream>
//#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "myfile.txt" 
using namespace std;
class WorkerManage
{
public:
	WorkerManage();
	void Show_Menu();
	~WorkerManage();
	void ExitSystem();
	//增加职工
	void Add_Emp();

	//保存文件
	void save();

	//统计人数
	int getEmpNum();
	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序
	void Sort_Emp();

	//清空
	void Clean_File();

	//判断职工是否存在
	int IsExist(int id);

	//记录文件中的人数个数
	int EmpNum;
	//员工数组的指针
	Worker** EmpArray;

	//标志文件是否为空
	bool FileIsEmpty;
};