#include <iostream>
#include <list>
#include <string>
using namespace std;
//案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高

//排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};
//按照年龄进行升序，如果年龄相同按照身高进行降序
bool compare(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}
void test()
{
	list<Person> L;

	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	cout << "------排序前--------" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << " 身高：" << it->m_Height << endl;
	}

	L.sort(compare);
	cout << "------排序后--------" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << " 身高：" << it->m_Height << endl;
	}
}
int main()
{
	test();
	return 0;
}