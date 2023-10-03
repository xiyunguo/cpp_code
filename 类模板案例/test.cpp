#define _CRT_SECURE_NO_WARNINGS 1
#include "myArray.hpp"
#include <string>
//�����������Ͳ���
void printInt(myArray<int>& p)
{
	for (int i = 0; i < p.getSize(); i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}
void test()
{
	cout << "------�����������Ͳ���----------" << endl;
	myArray<int> p1(10);
	for (int i = 0; i < 10; i++)
	{
		p1.push_back(i);
	}
	cout << "p1��ӡ�����" << endl;
	printInt(p1);
	cout << "p1�Ĵ�С��" << p1.getSize() << endl;
	cout << "p1��������" << p1.getCapacity() << endl;


	myArray<int> p2(p1);
	p2.pop_back();
	cout << "p2��ӡ�����" << endl;
	printInt(p2);
	cout << "p2�Ĵ�С��" << p2.getSize() << endl;
	cout << "p2��������" << p2.getCapacity() << endl;
}

//�����Զ�����������
class Person
{
public:
	Person(){}
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
//����Person  <<������
ostream& operator<<(ostream& out,Person& p)
{
	out << "������" << p.m_name << "  ���䣺" << p.m_age << endl;
	return out;
}

void printPerson(myArray<Person>& p)
{
	for (int i = 0; i < p.getSize(); i++)
	{
		cout << p[i];
	}
}
void test02()
{
	cout << "------�Զ����������Ͳ���----------" << endl;
	//��������
	myArray<Person> p1(10);
	Person pp1("����", 16);
	Person pp2("����", 24);
	Person pp3("����", 36);
	Person pp4("����", 89);
	Person pp5("С��", 77);
	//��������
	p1.push_back(pp1);
	p1.push_back(pp2);
	p1.push_back(pp3);
	p1.push_back(pp4);
	p1.push_back(pp5);
	cout << "p1��ӡ�����" << endl;
	printPerson(p1);

	cout << "p1�Ĵ�С��" << p1.getSize() << endl;
	cout << "p1��������" << p1.getCapacity() << endl;
	myArray<Person> p2(p1);
	p2.pop_back();
	cout << "p2��ӡ�����" << endl;
	printPerson(p2);
	cout << "p2�Ĵ�С��" << p2.getSize() << endl;
	cout << "p2��������" << p2.getCapacity() << endl;

}
int main()
{
	test();
	test02();
	return 0;

}