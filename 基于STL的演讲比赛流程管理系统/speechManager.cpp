#include "speechManager.h"
//���캯��
speechManager::speechManager()
{
	this->initSpeech();//��ʼ������
	this->createSpeaker();//��ʼ������12λѡ��
	this->loadRecord();//��ȡ�����¼
}
//չʾ�˵�
void speechManager::show_Menu()
{
	cout << "*********************************" << endl;
	cout << "*******  ��ӭ�μ��ݽ����� *******" << endl;
	cout << "*******  1.��ʼ�ݽ����� *********" << endl;
	cout << "*******  2.�鿴�����¼ *********" << endl;
	cout << "*******  3.��ձ�����¼ *********" << endl;
	cout << "*******  0.�˳��������� *********" << endl;
	cout << "*********************************" << endl;
}
//�˳�ϵͳ
void speechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
//��ʼ������
void speechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}
//��ʼ������12��ѡ��
void speechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//12��ѡ�ֱ��
		this->v1.push_back(10001+i);
		this->m_Speaker.insert(make_pair(10001 + i, sp));
	}
}
//��ʼ����
void speechManager::startSpeech()
{
	//��һ�ֱ���
	//1.��ǩ
	speechDraw();
	//2.����
	speechContest();
	//3.��ʾ�������
	showScore();
	//�ڶ��ֱ���
	this->m_Index++;
	//1.��ǩ
	speechDraw();
	//2.����
	speechContest();
	//3.��ʾ�������
	showScore();
	//4.�������
	saveRecord();


	//���ñ���
	this->initSpeech();//��ʼ������
	this->createSpeaker();//��ʼ������12λѡ��
	this->loadRecord();//��ȡ�����¼

	cout << "�����������" << endl;

	system("pause");
	system("cls");

}
//��ǩ
void speechManager::speechDraw()
{
	cout << "�ڡ�" << this->m_Index << "����ѡ�����ڳ�ǩ" << endl;
	cout << "-------------------------" << endl;
	cout << "��ǩ������£�" << endl;
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
//����
void speechManager::speechContest()
{
	cout << "-----------��" << this->m_Index << "�ֱ�����ʼ----------" << endl;
	multimap<double, int, greater<double>> groupScore;//��ʱ����������key���� valueѡ�ֱ��
	int num = 0;//��¼��Ա����6��Ϊ1��
	vector<int>v_Src;//��������Ա����
	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//60~100
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//����
		d.pop_back();//ȥ����߷�
		d.pop_front();//ȥ����ͷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);//��ȡ �ܷ�
		double avg = sum / (double)d.size();//��ȡƽ����

		this->m_Speaker[*it].m_Score[m_Index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));//6��һ�飬����ʱ��������
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << (*it).second << " ������" << m_Speaker[(*it).second].m_Name << " �÷֣�" << (*it).first << endl;
			}

			int count = 0;
			//ȡǰ3��
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
	cout << "-----------��" << this->m_Index << "�ֱ������----------" << endl;
	system("pause");
}
//��ʾ�������
void speechManager::showScore()
{
	cout << "----------��" << this->m_Index << "��ѡ�ֽ����������---------" << endl;
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
		cout << "��ţ�" << *it << " ������" << m_Speaker[*it].m_Name << " ������" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}
//�����¼
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
	cout << "��¼�Ѿ�����" << endl;
	this->fileIsEmpty = false;

}
//��ȡ��¼
void speechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
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
//��ʾ����÷�
void speechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ����¼Ϊ�գ�" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "��" <<
			"�ھ���ţ�" << m_Record[i][0] << " �÷֣�" << m_Record[i][1] << " "
			"�Ǿ���ţ�" << m_Record[i][2] << " �÷֣�" << m_Record[i][3] << " "
			"������ţ�" << m_Record[i][4] << " �÷֣�" << m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}
//��ռ�¼
void speechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��ʼ������
		this->initSpeech();
		//����ѡ��
		this->createSpeaker();
		//��ȡ�����¼
		this->loadRecord();
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//��������
speechManager::~speechManager()
{
	
}
