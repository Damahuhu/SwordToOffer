/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-02

Description:在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

bool Find(vector<vector<int> > array, int target) {
	int rows = array.size();
	if (rows == 0){
		return false;
	}

	int cols = array[0].size();
	if (cols == 0){
		return false;
	}

	int i = 0;
	int j = cols - 1;

	while (i < rows && j >= 0){
		if (target < array[i][j]){
			j--;
		}
		else if (target > array[i][j]){
			i++;
		}
		else if (target == array[i][j]){
			return true;
		}
	}
	return false;
}

void PrintRes(bool res){
	switch (res)
	{
	case true:
		std::cout << "Found!" << std::endl;
		break;
	case false:
		std::cout << "Have not found!" << std::endl;
		break;
	default:
		break;
	}
}

int main(){
	vector<vector<int> > array = {
		{ 1, 2, 8, 9 },
		{ 2, 4, 9, 12 },
		{ 4, 7, 10, 13 },
		{ 6, 8, 11, 15 },
	};

	int target = 7;

	DWORD start, stop;

	start = GetTickCount();
	bool isFount = Find(array, target);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(isFount);

	return 0;
}