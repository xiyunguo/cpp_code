#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

//������
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡְ����λ����
	virtual string getDeptName();
};