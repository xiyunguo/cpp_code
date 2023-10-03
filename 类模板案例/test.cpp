#define _CRT_SECURE_NO_WARNINGS 1
#include "myArray.hpp"
#include <string>
//内置数据类型测试
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
	cout << "------内置数据类型测试----------" << endl;
	myArray<int> p1(10);
	for (int i = 0; i < 10; i++)
	{
		p1.push_back(i);
	}
	cout << "p1打印输出：" << endl;
	printInt(p1);
	cout << "p1的大小：" << p1.getSize() << endl;
	cout << "p1的容量：" << p1.getCapacity() << endl;


	myArray<int> p2(p1);
	p2.pop_back();
	cout << "p2打印输出：" << endl;
	printInt(p2);
	cout << "p2的大小：" << p2.getSize() << endl;
	cout << "p2的容量：" << p2.getCapacity() << endl;
}

//测试自定义数据类型
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
//重载Person  <<操作符
ostream& operator<<(ostream& out,Person& p)
{
	out << "姓名：" << p.m_name << "  年龄：" << p.m_age << endl;
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
	cout << "------自定义数据类型测试----------" << endl;
	//创建数组
	myArray<Person> p1(10);
	Person pp1("韩信", 16);
	Person pp2("赵云", 24);
	Person pp3("阿离", 36);
	Person pp4("廉颇", 89);
	Person pp5("小明", 77);
	//插入数据
	p1.push_back(pp1);
	p1.push_back(pp2);
	p1.push_back(pp3);
	p1.push_back(pp4);
	p1.push_back(pp5);
	cout << "p1打印输出：" << endl;
	printPerson(p1);

	cout << "p1的大小：" << p1.getSize() << endl;
	cout << "p1的容量：" << p1.getCapacity() << endl;
	myArray<Person> p2(p1);
	p2.pop_back();
	cout << "p2打印输出：" << endl;
	printPerson(p2);
	cout << "p2的大小：" << p2.getSize() << endl;
	cout << "p2的容量：" << p2.getCapacity() << endl;

}
int main()
{
	test();
	test02();
	return 0;

}