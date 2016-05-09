/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-06

Description:һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
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