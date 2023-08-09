#include <iostream>
#include <ctime>
using namespace std;
//循环与数组的案例


//while循环案例：猜数字
int main1()
{
	//添加随机数种子
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	while (1)
	{
		int val = 0;
		cin >> val;
		if (val > num)
		{
			cout << "猜测过大" << endl;
		}
		else if (val < num)
		{
			cout << "猜测过小" << endl;
		}
		else
		{
			cout << "猜测正确" << endl;
			break;
		}
	}
	return 0;
}


//do...while案例：水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身
int main2()
{
	int i = 100;
	do
	{
		int a = i % 10;
		int b = i / 10 % 10;
		int c = i / 100 % 10;
		if (a*a*a + b*b*b + c*c*c == i)
		{
			cout << i << " ";
		}
		i++;
	} while (i<1000);
	return 0;
}
//数组元素逆置
int main3()
{
	int arr[5] = { 1,3,2,5,4 };
	cout << "数组逆置前： " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	//实现逆置
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	cout << "数组元素逆置后 " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
//冒泡
int main4()
{
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	for (int i = 0; i < 9 - 1; i++)
	{
		for (int j = 0; j < 9 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}