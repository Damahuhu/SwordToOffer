/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-06

Description: 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int xorEveryElement(vector<int> &data){
	int tem = 0;
	for (int i = 0; i < data.size(); i++){
		tem ^= data[i];
	}

	return tem;
}

int findFirstOneBit(int val){
	int index = 0;
	while ((val & 1) == 0){
		val = val >> 1;
		index++;
	}

	return index;
}


bool isInFirstArray(int val, int index){
	for (int i = 0; i < index; i++){
		val = val >> 1;
	}

	if ((val & 1) != 0){
		return true;
	}
		return false;
}

void FindNumsAppearOnce(vector<int> data, int* num1, int *num2){
	(*num1) = 0;
	(*num2) = 0;

	if (data.size() < 2){
		return;
	}

	//xor for every element
	int tem = xorEveryElement(data);

	//find first 1 bit
	int index = findFirstOneBit(tem);

	for (int i = 0; i < data.size(); i++){
		if (isInFirstArray(data[i], index)){
			(*num1) ^= data[i];
		}
		else{
			(*num2) ^= data[i];
		}
	}

	if (*num1 == 0 || * num2 == 0){
		(*num1) = 0;
		(*num2) = 0;
	}
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	vector<int> data = {1};
	int num1 = 0;
	int num2 = 0;

	DWORD start, stop;
	start = GetTickCount();
	FindNumsAppearOnce(data, &num1, &num2);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(num1);
	PrintRes(num2);

	return 0;
}
