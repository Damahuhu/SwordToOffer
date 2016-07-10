/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-07

Description: 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
             如果有多对数字的和等于S，输出两个数的乘积最小的。 

			 对应每个测试案例，输出两个数，小的先输出。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int> res;

	if (array.size() < 2){
		return res;
	}

	int first = 0;
	int second = 1;
	while (first < second){
		while (array[first] + array[second] < sum){
			second++;
		}

		if (array[first] + array[second] == sum){
			res.push_back(array[first]);
			res.push_back(array[second]);
			return res;
		}
		else if (array[first] + array[second] > sum){
			first++;
		}
		
		while (array[first] + array[second] > sum){
			second--;
		}

		if (array[first] + array[second] == sum){
			res.push_back(array[first]);
			res.push_back(array[second]);
			return res;
		}
	}
	
	return res;
}

void PrintRes(vector<int> res)
{
	for (auto i = 0; i < res.size(); i++){
		std::cout << res[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	vector<int> array = {1,2,3,4,5,6,7,8,9};
	int sum = 9;

	DWORD start, stop;
	start = GetTickCount();
	vector<int> res = FindNumbersWithSum(array, sum);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
