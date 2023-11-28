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
			cout << "ע���ɹ�" << endl;
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
			cout << "ע���ɹ�" << endl;
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
		//����Ա�˵�
		manage->operMenu();

		manager* man = (manager*)manage;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			man->addPerson();//����˺�
			cout << "����˺�" << endl;
		}
		else if (select == 2)
		{
			man->showPerson();//�鿴�˺�
			cout << "�鿴�˺�" << endl;
		}
		else if (select == 3)
		{
			man->showComputer();//�鿴������Ϣ
			cout << "�鿴����" << endl;
		}
		else if (select == 4)
		{
			man->cleanFile();//���ԤԼ
			cout << "���ԤԼ" << endl;
		}
		else
		{
			//ע��
			delete manage;
			cout << "ע���ɹ�" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ����֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				Person = new student(id, name, pwd);
				//ѧ���ӽ���
				studentMenu(Person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				Person = new teacher(id, name, pwd);
				//��ʦ�ӽ���
				teacherMenu(Person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��֤
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (name == fname && pwd == fpwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				Person = new manager(name, pwd);
				//����Ա�ӽ���
				managerMenu(Person);

				return;
			}
		}
	}
	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");
	return;

}



int main()
{
	int select = 0;
	
	while (true)
	{
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;
		switch (select)
		{
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
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
			cout << "�������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;

		}
	}
}