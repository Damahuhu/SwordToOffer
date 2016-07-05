/*************************************************

Copyright:***

Author:Hao Li

Date:2016-07-04

Description:把只包含因子2、3和5的数称作丑数（Ugly Number）。
            例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int findMinNum(int num1, int num2, int num3){
	int min = num1;

	if (min > num2){
		min = num2;
	}

	if (min > num3){
		min = num3;
	}

	return min;
}

int GetUglyNumber_Solution(int index) {
	if (index < 1){
		return 0;
	}

	vector<int> uglyNum;
	uglyNum.push_back(1);
	int T2 = 0;
	int T3 = 0;
	int T5 = 0;

	while (uglyNum.size() < index){
		int M = uglyNum[uglyNum.size() - 1];

		int M2 = 2 * uglyNum[T2];
		int M3 = 3 * uglyNum[T3];
		int M5 = 5 * uglyNum[T5];

		for (int i = T2; i < uglyNum.size(); i++){
			M2 = 2 * uglyNum[i];
			T2 = i;

			if (M2 > M){
				break;
			}
		}

		for (int i = T3; i < uglyNum.size(); i++){
			M3 = 3 * uglyNum[i];
			T3 = i;

			if (M3 > M){
				break;
			}
		}

		for (int i = T5; i < uglyNum.size(); i++){
			M5 = 5 * uglyNum[i];
			T5 = i;

			if (M5 > M){
				break;
			}
		}

		int newNum = findMinNum(M2, M3, M5);
		uglyNum.push_back(newNum);

		cout << newNum << endl;
	}

	return uglyNum[uglyNum.size() - 1];
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	int index = 10;

	DWORD start, stop;
	start = GetTickCount();
	int res = GetUglyNumber_Solution(index);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
