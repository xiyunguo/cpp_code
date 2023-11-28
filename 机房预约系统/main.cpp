#include <iostream>
#include <fstream>
#include <string>
#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;
void teacherMenu(identity*& teach)
{
	while (true)
	{
		teach->operMenu();
		teacher* tea = (teacher*)teach;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete teach;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void studentMenu(identity*& studen)
{
	while (true)
	{
		studen->operMenu();
		student* stu = (student*)studen;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else
		{
			delete studen;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void managerMenu(identity* &manage)
{
	while (true)
	{
		//管理员菜单
		manage->operMenu();

		manager* man = (manager*)manage;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			man->addPerson();//添加账号
			cout << "添加账号" << endl;
		}
		else if (select == 2)
		{
			man->showPerson();//查看账号
			cout << "查看账号" << endl;
		}
		else if (select == 3)
		{
			man->showComputer();//查看电脑信息
			cout << "查看电脑" << endl;
		}
		else if (select == 4)
		{
			man->cleanFile();//清空预约
			cout << "清空预约" << endl;
		}
		else
		{
			//注销
			delete manage;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}





	}
}


void Login(string filename,int type)
{
	identity* Person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				Person = new student(id, name, pwd);
				//学生子界面
				studentMenu(Person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				Person = new teacher(id, name, pwd);
				//教师子界面
				teacherMenu(Person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员验证
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (name == fname && pwd == fpwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				Person = new manager(name, pwd);
				//管理员子界面
				managerMenu(Person);

				return;
			}
		}
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
	return;

}



int main()
{
	int select = 0;
	
	while (true)
	{
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1:
			Login(STUDENT_FILE, 1);
			break;
		case 2:
			Login(TEACHER_FILE, 2);
			break;
		case 3:
			Login(ADMIN_FILE, 3);
			break;
		default:
			cout << "输入错误，请重新选择" << endl;
			system("pause");
			system("cls");
			break;

		}
	}
}