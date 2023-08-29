#define _CRT_SECURE_NO_WARNINGS 1
#include "WorkerManage.h"

WorkerManage::WorkerManage()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	//�ļ����������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;//�������
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->EmpArray = NULL;
		this->EmpNum = 0;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڣ������г�Ա
	int num = this->getEmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->EmpNum = num;
	//����ְ������������
	this->EmpArray = new Worker * [this->EmpNum];
	//��ʼ��ְ��
	this->init_Emp();
	
	//���Դ���
	//for (int i = 0; i < this->EmpNum; i++)
	//{
	//	cout << "ְ���ţ�" << this->EmpArray[i]->m_Id
	//		<< "ְ��������" << this->EmpArray[i]->m_Name
	//		<< "ְ����ţ�" << this->EmpArray[i]->m_DeptId << endl;
	//}
}
WorkerManage::~WorkerManage()
{
	if (this->EmpArray != NULL)
	{
		for (int i = 0; i < this->EmpNum; i++)
		{
			if (this->EmpArray[i] != NULL)
			{
				delete this->EmpArray[i];
			}
		}
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}
void WorkerManage::Show_Menu()
{
	cout << "******************************************" << endl;
	cout << "**********��ӭʹ��ְ������ϵͳ��**********" << endl;
	cout << "***********0.�˳��������*****************" << endl;
	cout << "***********1.����ְ����Ϣ*****************" << endl;
	cout << "***********2.��ʾְ����Ϣ*****************" << endl;
	cout << "***********3.ɾ����ְְ��*****************" << endl;
	cout << "***********4.�޸�ְ����Ϣ*****************" << endl;
	cout << "***********5.����ְ����Ϣ*****************" << endl;
	cout << "***********6.���ձ������*****************" << endl;
	cout << "***********7.��������ĵ�*****************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void WorkerManage::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//����ְ��
void WorkerManage::Add_Emp()
{
	cout << "������Ҫ���ְ������Ŀ��" << endl;

	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ��С
		int newsize = this->EmpNum + addNum;
		//�����¿ռ�
		Worker** newspace = new Worker* [newsize];

		//��ԭ�ռ������ݷŵ��¿ռ���
		if (this->EmpArray != NULL)
		{
			for (int i = 0; i < this->EmpNum; i++)
			{
				newspace[i] = this->EmpArray[i];
			}
		}
		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int selectid;
			cout << "������� " << i + 1 << " ����ְ�����" << endl;
			cin >> id;

			cout << "������� " << i + 1 << " ����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			
			Worker* worker = NULL;
			while (true)
			{
				cin >> selectid;
				if (selectid == 1 || selectid == 2 || selectid == 3)
				{
					break;
				}
				cout << "�������������ѡ��" << endl;
			}
			switch (selectid)
			{
			case 1:
				worker = new Employee(id, name, selectid);
				break;
			case 2:
				worker = new Manager(id, name, selectid);
				break;
			case 3:
				worker = new Boss(id, name, selectid);
				break;
			default:
				break;
			}
			newspace[this->EmpNum + i] = worker;
		}

		delete[] this->EmpArray;
		this->EmpArray = newspace;
		this->EmpNum = newsize;
		this->FileIsEmpty = false;
		cout << "�ɹ���� " << addNum << " ��ְ��" << endl;

		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManage::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->EmpNum; i++)
	{
		ofs << this->EmpArray[i]->m_Id << " "
			<< this->EmpArray[i]->m_Name << " "
			<< this->EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

int WorkerManage::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//��¼����
		num++;
	}
	ifs.close();
	return num;
}

//��ʼ��Ա��
void WorkerManage::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		//���ݲ�ͬ����id������ͬ����
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//��ʾְ��
void WorkerManage::Show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->EmpNum; i++)
		{
			this->EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


//ɾ��ְ��
void WorkerManage::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ��ְ���ı��" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//˵��index��λ��������Ҫɾ��
		{
			for (int i = index; i < this->EmpNum - 1; i++)
			{
				this->EmpArray[i] = this->EmpArray[i + 1];
			}
			this->EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}

	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
int WorkerManage::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->EmpNum; i++)
	{
		if (this->EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//�޸�ְ��
void WorkerManage::Mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸�ְ���ı��" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//˵��index��λ��������Ҫ�޸�
		{
			delete this->EmpArray[index];
			int Id = 0;
			string Name = "";
			int Did = 0;
			cout << "�鵽 " << id << "��ְ������������ְ���ţ�" << endl;
			cin >> Id;
			cout << "������������" << endl;
			cin >> Name;
			cout << "�������λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> Did;

			Worker* worker = NULL;
			switch (Did)
			{
			case 1:
				worker = new Employee(Id, Name, Did);
				break;
			case 2:
				worker = new Manager(Id, Name, Did);
				break;
			case 3:
				worker = new Boss(Id, Name, Did);
				break;
			default:
				break;
			}
			this->EmpArray[index] = worker;
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManage::Find_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "������Ҫ���ҵ�ְ�����" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�����" << endl;
			cin >> name;

			bool flag = false;//���ҵ��ı�־
			for (int i = 0; i < this->EmpNum; i++)
			{
				if (this->EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ" <<
						this->EmpArray[i]->m_Id << "����Ϣ����" << endl;
					flag = true;
					this->EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}

	}
	system("pause");
	system("cls");
}

//����
void WorkerManage::Sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->EmpArray[minOrMax]->m_Id > this->EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else if(select == 2)//����
				{
					if (this->EmpArray[minOrMax]->m_Id < this->EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "ѡ�����" << endl;
					system("pause");
					system("cls");
					return;
				}

			}
			if (i != minOrMax)
			{
				Worker* temp = this->EmpArray[i];
				this->EmpArray[i] = this->EmpArray[minOrMax];
				this->EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ���������Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}
}


//���
void WorkerManage::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		
		if (this->EmpArray != NULL)
		{
			for (int i = 0; i < this->EmpNum; i++)
			{
				if (this->EmpArray[i] != NULL)
				{
					delete this->EmpArray[i];
					this->EmpArray[i] = NULL;
				}
			}
			this->EmpNum = 0;
			delete[] this->EmpArray;
			this->EmpArray = NULL;
			this->FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
		
	}
	system("pause");
	system("cls");
}