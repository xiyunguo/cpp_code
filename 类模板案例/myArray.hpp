#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class myArray
{
public:
	//Ϊʲô���ﲻ�ù���Ĭ���޲ι��캯��Ҳ����ͨ��

	//�вι���
	myArray(int capacity)
	{
		//cout << "�вι��캯������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->arrayaddress = new T[this->m_Capacity];
	}
	//��������
	myArray(const myArray& arr)
	{
		//cout << "�������캯������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->arrayaddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->arrayaddress[i] = arr.arrayaddress[i];
		}
	}
	//��ֵ�����=����
	myArray& operator=(const myArray& arr)
	{
		//cout << "��ֵ���������" << endl;
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
	//����[]���������� arr[0]
	T& operator[](int index)
	{
		return this->arrayaddress[index];
	}

	//β�巨
	void push_back(const T& var)
	{
		if (this->m_Size == this->m_Capacity)
		{
			return;
		}
		this->arrayaddress[this->m_Size] = var;
		this->m_Size++;
	}
	//βɾ��
	void pop_back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//��ȡ��������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//��ȡ�����С
	int getSize()
	{
		return this->m_Size;
	}

	//��������
	~myArray()
	{
		if (this->arrayaddress != NULL)
		{
			//cout << "������������" << endl;
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