/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-28

Description: 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
             路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
			 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
			 例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
			 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
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
