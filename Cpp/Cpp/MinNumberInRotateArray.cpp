/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-02

Description:把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
			输入一个非递减序列的一个旋转，输出旋转数组的最小元素。
            例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int minNumInArray(vector<int> array, int index1, int index2){
	if (array.size() == 0 || array.size() < index1 + 1 || array.size() < index2 + 1){
		return 0;
	}

	int min = array[index1];
	for (int i = index1 + 1; i <= index2; i++){
		if (array[i] < min){
			min = array[i];
		}
	}

	return min;
}

int minNumberInRotateArray(vector<int> rotateArray) {
	if (rotateArray.size() == 0){
		return 0;
	}

	int index1 = 0;
	int index2 = rotateArray.size() - 1;
	int mid_index = index1;

	while (rotateArray[index1] >= rotateArray[index2]){
		if (index2 - index1 == 1){
			mid_index = index2;
			break;
		}

		mid_index = (index1 + index2) / 2;

		if (rotateArray[index1] == rotateArray[index2] && rotateArray[mid_index] == rotateArray[index2]){
			return minNumInArray(rotateArray, index1, index2);
		}

		if (rotateArray[mid_index] <= rotateArray[index2]){
			index2 = mid_index;
		}
		else if (rotateArray[mid_index] >= rotateArray[index1]){
			index1 = mid_index;
		}
	}

	return rotateArray[mid_index];
} 

void PrintRes(int res){
	std::cout << "res: " << res << std::endl;
}

int main(){
	vector<int> rotateArray = { 3, 4, 5, 1, 2 };
	int res = 0;

	DWORD start, stop;
	start = GetTickCount();
	res = minNumberInRotateArray(rotateArray);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}