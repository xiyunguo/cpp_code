#pragma once
#include <iostream>
#include <fstream>
#include "globalFile.h"
#include <map>
using namespace std;
class orderFile
{
public:
	//���캯��
	orderFile();
	//����ԤԼ��¼
	void updateOrder();

	map<int, map<string, string>> m_orderDate;//��¼������
	int m_Size;//ԤԼ��¼����

};
