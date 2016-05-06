/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-02

Description:��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
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