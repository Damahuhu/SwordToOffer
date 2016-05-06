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

int minNumberInRotateArray(vector<int> rotateArray) {

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