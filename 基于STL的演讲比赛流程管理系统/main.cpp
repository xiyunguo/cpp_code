#include<iostream>
#include "speechManager.h"
#include<ctime>
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	speechManager sm;
	//测试代码
	/*for (vector<int>::iterator it = sm.v1.begin(); it != sm.v1.end(); it++)
	{
		cout << "编号：" << *it << " 姓名：" << sm.m_Speaker[*it].m_Name << " 成绩: "<<sm.m_Speaker[*it].m_Score[0]<<endl;
	}*/
	int choice = 0;//用来储存用户的选项
	while (true)
	{
		sm.show_Menu();
		cout << "请选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看记录
			sm.showRecord();
			break;
		case 3://清空记录
			sm.clearRecord();
			break;
		case 0://退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	
	return 0;
}