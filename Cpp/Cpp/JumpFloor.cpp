/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-06

Description:一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int jumpFloor(int number) {
	int res = 0;
	if (number == 1){
		return 1;
	}
	else if (number == 2){
		return 2;
	}

	int preTwo = 1;
	int preOne = 2;
	for (int i = 3; i <= number; i++){
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
	int n = 3;

	DWORD start, stop;
	start = GetTickCount();
	res = jumpFloor(n);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}