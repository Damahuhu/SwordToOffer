/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-31

Description: 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
**************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <windows.h>
#include <functional>

using namespace std;

typedef multiset<int, greater<int> > intMultiSet;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
	intMultiSet ms;
	vector<int> res;

	if (input.size() < k){
		return res;
	}

	for (auto i = 0; i < input.size(); i++){
		if (ms.size() < k){
			ms.insert(input[i]);
		}
		else{
			if (input[i] < (*ms.begin())){
				ms.erase(*ms.begin());
				ms.insert(input[i]);
			}
		}
	}

	for (auto it = ms.begin(); it != ms.end(); it++){
		res.push_back(*it);
	}

	return res;
}

void PrintRes(vector<int>& res)
{
	for (auto i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> input = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int k = 4;

	DWORD start, stop;
	start = GetTickCount();
	vector<int> res = GetLeastNumbers_Solution(input, k);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}