/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-28

Description: ������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
             ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
			 ���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
			 ���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
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
