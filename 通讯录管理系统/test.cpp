#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
//�˵�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "****** 1.�����ϵ�� ******" << endl;
	cout << "****** 2.��ʾ��ϵ�� ******" << endl;
	cout << "****** 3.ɾ����ϵ�� ******" << endl;
	cout << "****** 4.������ϵ�� ******" << endl;
	cout << "****** 5.�޸���ϵ�� ******" << endl;
	cout << "****** 6.�����ϵ�� ******" << endl;
	cout << "****** 0.�˳�ͨѶ¼ ******" << endl;
	cout << "**************************" << endl;
}



int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	int select = 0;//�����û�ѡ������ı���
	while (true)
	{
		showMenu();//�˵�����
		cin >> select;
		switch (select)
		{
		case 1://���
			addPerson(&abs);
			break;
		case 2://��ʾ
			showPerson(&abs);
			break;
		case 3://ɾ��
			deletePerson(&abs);
			break;
		case 4://����
			searchPerson(&abs);
			break;
		case 5://�޸�
			modifyPerson(&abs);
			break;
		case 6://���
			cleanPerson(&abs);
			break;
		case 0://�˳�
			cout << "�˳��ɹ�����ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	return 0;
}