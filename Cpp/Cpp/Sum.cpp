/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-09

Description: 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

typedef int (*fun)(int n);

static int Sum_Return(int n){
	return 0;
}

static int Sum_Solution(int n){
	static fun f[2] = { Sum_Return, Sum_Solution };
	return n + f[!!n](n - 1);
}

//int Sum_Solution(int n) {
//	if (n < 0){
//		return 0;
//	}
//
//	int res = 1;
//	if (n == 1){
//		return res;
//	}
//	else{
//		res = Sum_Solution(n - 1) + n;
//	}
//
//	return res;
//}

void PrintRes(int res)
{
	cout << "res:" << res << endl;
}

int main()
{
	int n = 7;

	DWORD start, stop;
	start = GetTickCount();
	int res = Sum_Solution(n);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
