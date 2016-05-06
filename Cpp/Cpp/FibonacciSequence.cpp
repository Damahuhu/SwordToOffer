/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-06

Description:大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

//recursion
//int Fibonacci(int n)
//{
//	if (n < 0){
//		return -1;
//	}
//	if (n == 0){
//		return 0;
//	}
//	if (n == 1){
//		return 1;
//	}
//
//	return (Fibonacci(n - 1) + Fibonacci(n - 2));
//
//}

int Fibonacci(int n)
{
	int res = 0;
	if (n == 0){
		return 0;
	}
	else if (n == 1){
		return 1;
	}

	int preTwo = 0;
	int preOne = 1;
	for (int i = 2; i <= n; i++){
		res = preTwo + preOne;
		preTwo = preOne;
		preOne = res;
	}

	return res;
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	int res = 0;
	int n = 7;

	DWORD start, stop;
	start = GetTickCount();
	res = Fibonacci(n);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}