#pragma once
#include <iostream>
#include <fstream>
#include "globalFile.h"
#include <map>
using namespace std;
class orderFile
{
public:
	//构造函数
	orderFile();
	//更新预约记录
	void updateOrder();

	map<int, map<string, string>> m_orderDate;//记录的容器
	int m_Size;//预约记录条数

};
