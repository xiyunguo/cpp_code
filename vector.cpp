#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1.vector存放自定义数据类型
class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
//void bianli(Person& p)
//{
//	cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << endl;
//}
void test()
{
	Person p1("Tom", 18);
	Person p2("hue", 22);
	Person p3("Too", 26);
	Person p4("Faker", 27);
	Person p5("Curry", 20);
	Person p6("green", 22);
	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << endl;
	}
	//for_each(v.begin(), v.end(), bianli);
}

void test02()
{
	Person p1("Tom", 18);
	Person p2("hue", 22);
	Person p3("Too", 26);
	Person p4("Faker", 27);
	Person p5("Curry", 20);
	Person p6("green", 22);
	vector<Person*> v;
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << ":姓名：" << (*it)->m_name << " 年龄：" << (*it)->m_age << endl;
	}
}


//2.vector中嵌套vector存放数据
void test03()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}

}

int main()
{
	test();
	test02();
	test03();
	return 0;
}