/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-28

Description: 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
             每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
			 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
			 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
**************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

int movingCount(int threshold, int rows, int cols, bool *visibleTab, int startX, int startY)
{
	if (startX < 0 || startX >= cols || startY < 0 || startY >= rows){
		return 0;
	}

	int res = 0;
	int index = startY*cols + startX;
	string xStr = to_string(startX);
	string yStr = to_string(startY);

	int total = 0;
	for (auto it = xStr.begin(); it != xStr.end(); it++){
		total += *it - '0';
	}

	for (auto it = yStr.begin(); it != yStr.end(); it++){
		total += *it - '0';
	}

	if (!visibleTab[index] && total <= threshold){
		visibleTab[index] = true;
		res++;

		int upNum = movingCount(threshold, rows, cols, visibleTab, startX, startY - 1);
		int downNum = movingCount(threshold, rows, cols, visibleTab, startX, startY + 1);
		int leftNum = movingCount(threshold, rows, cols, visibleTab, startX - 1, startY);
		int rightNum = movingCount(threshold, rows, cols, visibleTab, startX + 1, startY);

		res += (upNum + downNum + leftNum + rightNum);
	}

	return res;
}

int movingCount(int threshold, int rows, int cols)
{
	if (rows < 0 || cols < 0){
		return 0;
	}

	bool *visibleTab = (bool*)malloc(sizeof(bool) * rows * cols);
	memset(visibleTab, 0, sizeof(bool) * rows * cols);

	int res = movingCount(threshold, rows, cols, visibleTab, 0, 0);
	free(visibleTab);
	visibleTab = NULL;

	return res;
}

void PrintRes(int res)
{
	cout << "res: " << res << endl;
}

int main()
{
	int threshold = 18;
	int rows = 50;
	int cols = 50;

	DWORD start, stop;
	start = GetTickCount();
	int res = movingCount(threshold, rows, cols);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
