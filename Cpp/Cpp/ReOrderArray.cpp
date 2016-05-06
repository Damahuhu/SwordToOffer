/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-09

Description: 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
             所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

bool isEven(int num){
	if (num % 2 == 0){
		return true;
	}

	return false;
}

void reOrderArray(vector<int> &array) {
	int firstEvenIndex = -1;
	int oddIndex = -1;

	for (int i = 0; i < array.size(); i++){
		if (isEven(array[i])){
			firstEvenIndex = i;
			break;
		}
	}

	if (firstEvenIndex == -1){
		return;
	}

	for (int i = 0; i < array.size(); i++){
		if (!isEven(array[i])){
			oddIndex = i;

			if (oddIndex > firstEvenIndex){
				int tem = array[oddIndex];
				for (int i = oddIndex; i > firstEvenIndex; i--){
					array[i] = array[i - 1];
				}
				array[firstEvenIndex] = tem;
				firstEvenIndex++;
			}
		}
	}
}

void PrintRes(vector<int> &array)
{
	for (auto i = 0; i < array.size(); i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	vector<int> array = {1, 4, 3, 5, 8};

	DWORD start, stop;
	start = GetTickCount();
	reOrderArray(array);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(array);
	return 0;
}