#include<iostream>
#include "speechManager.h"
#include<ctime>
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	speechManager sm;
	//���Դ���
	/*for (vector<int>::iterator it = sm.v1.begin(); it != sm.v1.end(); it++)
	{
		cout << "��ţ�" << *it << " ������" << sm.m_Speaker[*it].m_Name << " �ɼ�: "<<sm.m_Speaker[*it].m_Score[0]<<endl;
	}*/
	int choice = 0;//���������û���ѡ��
	while (true)
	{
		sm.show_Menu();
		cout << "��ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴��¼
			sm.showRecord();
			break;
		case 3://��ռ�¼
			sm.clearRecord();
			break;
		case 0://�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	
	return 0;
}