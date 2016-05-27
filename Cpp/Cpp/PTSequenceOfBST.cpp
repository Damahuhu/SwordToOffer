/*************************************************
Copyright:***

Author: Hao Li

Date: 2016-05-27

Description: ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No��
             �������������������������ֶ�������ͬ��
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

bool VerifySquenceOfBST(vector<int> sequence) {
	size_t arrayLen = sequence.size();
	if (arrayLen == 0){
		return false;
	}

	int rootValue = sequence[arrayLen - 1];

	vector<int> leftArray;
	vector<int> rightArray;
	int leftCount = 0;
	for (int i = 0; i < arrayLen - 1; i++){
		if (sequence[i] < rootValue){
			leftArray.push_back(sequence[i]);
			leftCount++;
		}
		else{
			break;
		}
	}

	for (int i = leftCount; i < arrayLen - 1; i++){
		if (sequence[i] < rootValue){
			return false;
		}
		else{
			rightArray.push_back(sequence[i]);
		}
	}

	if (leftArray.size() != 0 && !VerifySquenceOfBST(leftArray)){
		return false;
	}

	if (rightArray.size() != 0 && !VerifySquenceOfBST(rightArray)){
		return false;
	}

	return true;
}

void PrintRes(bool res)
{
	if (res){
		std::cout << "yes" << std::endl;
	}
	else{
		std::cout << "no" << std::endl;
	}
}

int main()
{
	vector<int> sequence = { 5, 7, 6, 9, 11, 10, 8 };

	DWORD start, stop;
	start = GetTickCount();
	bool res = VerifySquenceOfBST(sequence);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}