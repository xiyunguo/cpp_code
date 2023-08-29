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
	//����ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//ͳ������
	int getEmpNum();
	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����
	void Sort_Emp();

	//���
	void Clean_File();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//��¼�ļ��е���������
	int EmpNum;
	//Ա�������ָ��
	Worker** EmpArray;

	//��־�ļ��Ƿ�Ϊ��
	bool FileIsEmpty;
};