/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-12

Description: 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> res;

	int rows = matrix.size();
	if (rows == 0){
		return res;
	}
	int cols = matrix[0].size();

	int count = 0;
	int minRow = 0;
	int minCol = 0;
	int maxRow = rows - 1;
	int maxCol = cols - 1;
	int row = 0;
	int col = 0;
	while (count < rows*cols){
		while (col <= maxCol){
			res.push_back(matrix[row][col]);
			col++;
			count++;
		}
		col--;
		row++;

		if (count >= rows*cols){
			break;
		}

		while (row <= maxRow){
			res.push_back(matrix[row][col]);
			row++;
			count++;
		}
		row--;
		col--;

		if (count >= rows*cols){
			break;
		}

		while (col >= minCol){
			res.push_back(matrix[row][col]);
			col--;
			count++;
		}
		col++;
		row--;

		minRow++;

		if (count >= rows*cols){
			break;
		}

		while (row >= minRow){
			res.push_back(matrix[row][col]);
			row--;
			count++;
		}
		row++;
		col++;

		minCol++;
		maxRow--;
		maxCol--;
	}

	return res;
}

void printRes(const vector<int> &res){
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}

	cout << endl;
}

int main()
{
	//vector<vector<int> > matrix = {
	//	{ 1, 2, 3, 4 },
	//	{ 5, 6, 7, 8 },
	//	{ 9, 10, 11, 12 },
	//	{ 13, 14, 15, 16 },
	//};

	vector<vector<int> > matrix = { {1}, {2}, {3}, {4}, {5} };

	DWORD start, stop;
	start = GetTickCount();
	vector<int> res = printMatrix(matrix);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	printRes(res);

	return 0;
}