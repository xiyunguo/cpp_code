#pragma once
#include "speaker.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
#include<fstream>
using namespace std;
class speechManager
{
public:
	//构造函数
	speechManager();
	//析构函数
	~speechManager();
	//展示菜单
	void show_Menu();
	//退出系统
	void exitSystem();
	//初始化属性
	void initSpeech();
	//初始化创建12名选手
	void createSpeaker();
	//开始比赛
	void startSpeech();
	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//显示晋级结果
	void showScore();
	//保存记录
	void saveRecord();
	//读取记录
	void loadRecord();
	//显示往届得分
	void showRecord();
	//清空记录
	void clearRecord();

	//添加属性
	vector<int>v1;//存放12人编号
	vector<int>v2;//存放第二轮晋级6人编号
	vector<int>vVictory;//存放前三编号
	map<int, speaker> m_Speaker;//存放编号以及对应的具体选手
	int m_Index;//比赛轮次

	bool fileIsEmpty;//文件为空的标志
	map<int, vector<string>> m_Record;//往届记录


};