#define _CRT_SECURE_NO_WARNINGS 1
#include "WorkerManage.h"

WorkerManage::WorkerManage()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	//文件不存在情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;//测试输出
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->EmpArray = NULL;
		this->EmpNum = 0;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，且已有成员
	int num = this->getEmpNum();
	cout << "职工个数为：" << num << endl;
	this->EmpNum = num;
	//根据职工数创建数组
	this->EmpArray = new Worker * [this->EmpNum];
	//初始化职工
	this->init_Emp();
	
	//测试代码
	//for (int i = 0; i < this->EmpNum; i++)
	//{
	//	cout << "职工号：" << this->EmpArray[i]->m_Id
	//		<< "职工姓名：" << this->EmpArray[i]->m_Name
	//		<< "职工编号：" << this->EmpArray[i]->m_DeptId << endl;
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
	cout << "**********欢迎使用职工管理系统！**********" << endl;
	cout << "***********0.退出管理程序*****************" << endl;
	cout << "***********1.增加职工信息*****************" << endl;
	cout << "***********2.显示职工信息*****************" << endl;
	cout << "***********3.删除离职职工*****************" << endl;
	cout << "***********4.修改职工信息*****************" << endl;
	cout << "***********5.查找职工信息*****************" << endl;
	cout << "***********6.按照编号排序*****************" << endl;
	cout << "***********7.清空所有文档*****************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void WorkerManage::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//增加职工
void WorkerManage::Add_Emp()
{
	cout << "请输入要添加职工的数目：" << endl;

	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newsize = this->EmpNum + addNum;
		//开辟新空间
		Worker** newspace = new Worker* [newsize];

		//将原空间下内容放到新空间下
		if (this->EmpArray != NULL)
		{
			for (int i = 0; i < this->EmpNum; i++)
			{
				newspace[i] = this->EmpArray[i];
			}
		}
		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int selectid;
			cout << "请输入第 " << i + 1 << " 个新职工编号" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			
			Worker* worker = NULL;
			while (true)
			{
				cin >> selectid;
				if (selectid == 1 || selectid == 2 || selectid == 3)
				{
					break;
				}
				cout << "输入错误，请重新选择" << endl;
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
		cout << "成功添加 " << addNum << " 名职工" << endl;

		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
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
		//记录人数
		num++;
	}
	ifs.close();
	return num;
}

//初始化员工
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
		//根据不同部门id创建不同对象
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

//显示职工
void WorkerManage::Show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
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


//删除职工
void WorkerManage::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要删除职工的编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//说明index上位置数据需要删除
		{
			for (int i = index; i < this->EmpNum - 1; i++)
			{
				this->EmpArray[i] = this->EmpArray[i + 1];
			}
			this->EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}

	}
	system("pause");
	system("cls");
}

//判断职工是否存在
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

//修改职工
void WorkerManage::Mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改职工的编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//说明index上位置数据需要修改
		{
			delete this->EmpArray[index];
			int Id = 0;
			string Name = "";
			int Did = 0;
			cout << "查到 " << id << "号职工，请输入新职工号：" << endl;
			cin >> Id;
			cout << "请输入新姓名" << endl;
			cin >> Name;
			cout << "请输入岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			cout << "修改成功" << endl;
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManage::Find_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入要查找的职工编号" << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要查找的姓名" << endl;
			cin >> name;

			bool flag = false;//查找到的标志
			for (int i = 0; i < this->EmpNum; i++)
			{
				if (this->EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为" <<
						this->EmpArray[i]->m_Id << "的信息如下" << endl;
					flag = true;
					this->EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}

	}
	system("pause");
	system("cls");
}

//排序
void WorkerManage::Sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->EmpArray[minOrMax]->m_Id > this->EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else if(select == 2)//降序
				{
					if (this->EmpArray[minOrMax]->m_Id < this->EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "选择错误" << endl;
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
		cout << "排序成功，排序结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
}


//清空
void WorkerManage::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

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
		cout << "清空成功" << endl;
		
	}
	system("pause");
	system("cls");
}