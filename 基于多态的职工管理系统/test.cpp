#define _CRT_SECURE_NO_WARNINGS 1
#include "WorkerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


int main()
{
	////���Զ�̬
	//Worker* wk = new Employee(1, "����", 1);
	//wk->showInfo();
	//delete wk;
	//Worker* wk1 = new Manager(2, "����", 2);
	//wk1->showInfo();
	//delete wk1;
	//Worker* wk2 = new Boss(3, "����", 3);
	//wk2->showInfo();
	//delete wk2;


	WorkerManage wm;
	
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://����ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}