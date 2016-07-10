/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-10

Description: 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int Add(int num1, int num2)
{
	int sum = 0;
	while (num2 != 0){
		sum = num1 ^ num2;
		num2 = (num1 & num2) << 1;

		num1 = sum;
	}

	return num1;
}

void PrintRes(int res)
{
	cout << "res:" << res << endl;
}

int main()
{
	int num1 = 7;
	int num2 = 5;

	DWORD start, stop;
	start = GetTickCount();
	int res = Add(num1, num2);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
