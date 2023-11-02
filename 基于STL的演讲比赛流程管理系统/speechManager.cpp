#include "speechManager.h"
//构造函数
speechManager::speechManager()
{
	this->initSpeech();//初始化属性
	this->createSpeaker();//初始化创建12位选手
	this->loadRecord();//获取往届记录
}
//展示菜单
void speechManager::show_Menu()
{
	cout << "*********************************" << endl;
	cout << "*******  欢迎参加演讲比赛 *******" << endl;
	cout << "*******  1.开始演讲比赛 *********" << endl;
	cout << "*******  2.查看往届记录 *********" << endl;
	cout << "*******  3.清空比赛记录 *********" << endl;
	cout << "*******  0.退出比赛程序 *********" << endl;
	cout << "*********************************" << endl;
}
//退出系统
void speechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
//初始化属性
void speechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}
//初始化创建12名选手
void speechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//12名选手编号
		this->v1.push_back(10001+i);
		this->m_Speaker.insert(make_pair(10001 + i, sp));
	}
}
//开始比赛
void speechManager::startSpeech()
{
	//第一轮比赛
	//1.抽签
	speechDraw();
	//2.比赛
	speechContest();
	//3.显示晋级结果
	showScore();
	//第二轮比赛
	this->m_Index++;
	//1.抽签
	speechDraw();
	//2.比赛
	speechContest();
	//3.显示晋级结果
	showScore();
	//4.保存分数
	saveRecord();


	//重置比赛
	this->initSpeech();//初始化属性
	this->createSpeaker();//初始化创建12位选手
	this->loadRecord();//获取往届记录

	cout << "本届比赛结束" << endl;

	system("pause");
	system("cls");

}
//抽签
void speechManager::speechDraw()
{
	cout << "第《" << this->m_Index << "》轮选手正在抽签" << endl;
	cout << "-------------------------" << endl;
	cout << "抽签结果如下：" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------" << endl;
	system("pause");
	cout << endl;
}
//比赛
void speechManager::speechContest()
{
	cout << "-----------第" << this->m_Index << "轮比赛开始----------" << endl;
	multimap<double, int, greater<double>> groupScore;//临时容器，保存key分数 value选手编号
	int num = 0;//记录人员数，6个为1组
	vector<int>v_Src;//比赛的人员容器
	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//遍历所有参赛选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//60~100
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//排序
		d.pop_back();//去掉最高分
		d.pop_front();//去掉最低分
		double sum = accumulate(d.begin(), d.end(), 0.0f);//获取 总分
		double avg = sum / (double)d.size();//获取平均分

		this->m_Speaker[*it].m_Score[m_Index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));//6人一组，用临时容器保存
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << (*it).second << " 姓名：" << m_Speaker[(*it).second].m_Name << " 得分：" << (*it).first << endl;
			}

			int count = 0;
			//取前3名
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "-----------第" << this->m_Index << "轮比赛完毕----------" << endl;
	system("pause");
}
//显示晋级结果
void speechManager::showScore()
{
	cout << "----------第" << this->m_Index << "轮选手晋级结果如下---------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it << " 姓名：" << m_Speaker[*it].m_Name << " 分数：" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}
//保存记录
void speechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
	this->fileIsEmpty = false;

}
//读取记录
void speechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}
//显示往届得分
void speechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在，或记录为空！" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届" <<
			"冠军编号：" << m_Record[i][0] << " 得分：" << m_Record[i][1] << " "
			"亚军编号：" << m_Record[i][2] << " 得分：" << m_Record[i][3] << " "
			"季军编号：" << m_Record[i][4] << " 得分：" << m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}
//清空记录
void speechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化属性
		this->initSpeech();
		//创建选手
		this->createSpeaker();
		//获取往届记录
		this->loadRecord();
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
speechManager::~speechManager()
{
	
}
