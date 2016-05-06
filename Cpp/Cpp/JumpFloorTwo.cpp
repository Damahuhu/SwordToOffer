/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-06

Description:一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int jumpFloorII(int number) {
	if (number <= 0){
		return -1;
	}

	return std::pow(2, number - 1);
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	int res = 0;
	int n = 3;

	DWORD start, stop;
	start = GetTickCount();
	res = jumpFloorII(n);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}