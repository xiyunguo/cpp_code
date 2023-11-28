#pragma once
#include <iostream>
#include "identity.h"
#include "orderFile.h"
#include <vector>
using namespace std;
class teacher :public identity
{
public:
	teacher();
	teacher(int id, string name, string pwd);
	virtual void operMenu();

	void showAllOrder();
	void validOrder();

	int m_EmpId;
};
