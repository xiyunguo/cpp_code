#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

//������
class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡְ����λ����
	virtual string getDeptName();
};