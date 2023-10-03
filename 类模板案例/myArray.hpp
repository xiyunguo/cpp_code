#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class myArray
{
public:
	//为什么这里不用构造默认无参构造函数也能跑通？

	//有参构造
	myArray(int capacity)
	{
		//cout << "有参构造函数调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->arrayaddress = new T[this->m_Capacity];
	}
	//拷贝构造
	myArray(const myArray& arr)
	{
		//cout << "拷贝构造函数调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->arrayaddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->arrayaddress[i] = arr.arrayaddress[i];
		}
	}
	//赋值运算符=重载
	myArray& operator=(const myArray& arr)
	{
		//cout << "赋值运算符重载" << endl;
		if (this->arrayaddress != NULL)
		{
			delete[] this->arrayaddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->arrayaddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->arrayaddress[i] = arr.arrayaddress[i];
		}
		return *this;
	}
	//索引[]操作符重载 arr[0]
	T& operator[](int index)
	{
		return this->arrayaddress[index];
	}

	//尾插法
	void push_back(const T& var)
	{
		if (this->m_Size == this->m_Capacity)
		{
			return;
		}
		this->arrayaddress[this->m_Size] = var;
		this->m_Size++;
	}
	//尾删法
	void pop_back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//获取数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//获取数组大小
	int getSize()
	{
		return this->m_Size;
	}

	//析构函数
	~myArray()
	{
		if (this->arrayaddress != NULL)
		{
			//cout << "析构函数调用" << endl;
			delete[] this->arrayaddress;
			this->arrayaddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}

private:
	int m_Capacity;
	int m_Size;
	T* arrayaddress;
};