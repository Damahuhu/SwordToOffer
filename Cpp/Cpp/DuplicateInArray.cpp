/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-10

Description: 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
	if (length < 2){
		return false;
	}

	for (int i = 0; i < length; i++){
		if (numbers[i] != i){
			int m = numbers[i];

			if (numbers[i] == numbers[m]){
				*duplication = numbers[i];
				return true;
			}

			int tem = numbers[m];
			numbers[m] = numbers[i];
			numbers[i] = tem;
		}
	}

	return false;
}

void PrintRes(int res)
{
	cout << "res:" << res << endl;
}

int main()
{
	int numbers[] = {1, 2, 3, 4, 2, 4};
	int length = 6;
	int duplication = 0;

	DWORD start, stop;
	start = GetTickCount();
	bool isDuplicate = duplicate(numbers, length, &duplication);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	if (isDuplicate)
		PrintRes(duplication);

	return 0;
}
