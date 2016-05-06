/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-06

Description:һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
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