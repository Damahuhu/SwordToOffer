/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-10

Description: ��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� 
������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ�
���ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3��
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
