/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-28

Description: �����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
             ·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
			 ���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� 
			 ���� a b c e s f c s a d e e �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·����
			 ��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

bool hasPath(char* matrix, bool *visitedTab, int rows, int cols, int x, int y, char* str)
{
	if (*str == '\0'){
		return true;
	}

	if (x < 0 || x >= cols || y < 0 || y >= rows){
		return false;
	}

	int index = y*cols + x;
	if (*str == matrix[index] && !visitedTab[index]){
		visitedTab[index] = true;

		bool res =  hasPath(matrix, visitedTab, rows, cols, x - 1, y, str + 1)
			|| hasPath(matrix, visitedTab, rows, cols, x + 1, y, str + 1)
			|| hasPath(matrix, visitedTab, rows, cols, x, y - 1, str + 1)
			|| hasPath(matrix, visitedTab, rows, cols, x, y + 1, str + 1);

		if (!res){
			visitedTab[index] = false;
		}

		return res;
	}

	return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == NULL || rows < 0 || cols < 0 || str == NULL){
		return false;
	}

	bool *visitedTab = (bool*)malloc(rows*cols*sizeof(bool));
	memset(visitedTab, 0, rows*cols*sizeof(bool));

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if (hasPath(matrix, visitedTab, rows, cols, j, i, str)){
				free(visitedTab);
				visitedTab = NULL;

				return true;
			}
		}
	}

	free(visitedTab);
	visitedTab = NULL;

	return false;
}

void PrintRes(bool res)
{
	switch (res){
	case true:
		cout << "yes!" << endl;
		break;
	case false:
		cout << "no!" << endl;
		break;
	}
}

int main()
{
	char* matrix = "ABCESFCSADEE";
	int rows = 3;
	int cols = 4;
	char* str = "BCCED";

	DWORD start, stop;
	start = GetTickCount();
	bool res = hasPath(matrix, rows, cols, str);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
