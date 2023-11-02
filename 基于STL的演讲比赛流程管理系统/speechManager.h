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
	//���캯��
	speechManager();
	//��������
	~speechManager();
	//չʾ�˵�
	void show_Menu();
	//�˳�ϵͳ
	void exitSystem();
	//��ʼ������
	void initSpeech();
	//��ʼ������12��ѡ��
	void createSpeaker();
	//��ʼ����
	void startSpeech();
	//��ǩ
	void speechDraw();
	//����
	void speechContest();
	//��ʾ�������
	void showScore();
	//�����¼
	void saveRecord();
	//��ȡ��¼
	void loadRecord();
	//��ʾ����÷�
	void showRecord();
	//��ռ�¼
	void clearRecord();

	//�������
	vector<int>v1;//���12�˱��
	vector<int>v2;//��ŵڶ��ֽ���6�˱��
	vector<int>vVictory;//���ǰ�����
	map<int, speaker> m_Speaker;//��ű���Լ���Ӧ�ľ���ѡ��
	int m_Index;//�����ִ�

	bool fileIsEmpty;//�ļ�Ϊ�յı�־
	map<int, vector<string>> m_Record;//�����¼


};