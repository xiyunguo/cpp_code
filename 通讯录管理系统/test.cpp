#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "****** 1.添加联系人 ******" << endl;
	cout << "****** 2.显示联系人 ******" << endl;
	cout << "****** 3.删除联系人 ******" << endl;
	cout << "****** 4.查找联系人 ******" << endl;
	cout << "****** 5.修改联系人 ******" << endl;
	cout << "****** 6.清空联系人 ******" << endl;
	cout << "****** 0.退出通讯录 ******" << endl;
	cout << "**************************" << endl;
}



int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	int select = 0;//创建用户选择输入的变量
	while (true)
	{
		showMenu();//菜单调用
		cin >> select;
		switch (select)
		{
		case 1://添加
			addPerson(&abs);
			break;
		case 2://显示
			showPerson(&abs);
			break;
		case 3://删除
			deletePerson(&abs);
			break;
		case 4://查找
			searchPerson(&abs);
			break;
		case 5://修改
			modifyPerson(&abs);
			break;
		case 6://清空
			cleanPerson(&abs);
			break;
		case 0://退出
			cout << "退出成功，欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	return 0;
}