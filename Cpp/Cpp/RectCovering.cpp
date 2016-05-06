/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-06

Description:我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
            请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int rectCover(int number) {
	int res = 0;

	if (number <= 0){
		return 0;
	}
	if (number == 1){
		return 1;
	}
	if (number == 2){
		return 2;
	}

	int preTwo = 1;
	int preOne = 2;
    
	for (int i = 3; i <= number; i++){
		res = preOne + preTwo;
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
	res = rectCover(n);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}