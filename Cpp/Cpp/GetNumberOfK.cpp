/*************************************************

Copyright:***

Author:Hao Li

Date:2016-07-04

Description:统计一个数字在排序数组中出现的次数。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int getFirstK(vector<int> data, int k, int start, int end){
	if (data.size() == 0 || start > end){
		return -1;
	}

	int res = -1;
	int mid = (start + end) / 2;

	if (k == data[mid]){
		if (mid == start){
			res = start;
		}
		else if (data[mid - 1] < k){
			res = mid;
		}
		else{
			res = getFirstK(data, k, start, mid-1);
		}
	}
	else if (k < data[mid]){
		res = getFirstK(data, k, start, mid-1);
	}
	else if (k > data[mid]){
		res = getFirstK(data, k, mid + 1, end);
	}

	return res;
}

int getLastK(vector<int> data, int k, int start, int end){
	if (data.size() == 0 || start > end){
		return -1;
	}

	int res = -1;
	int mid = (start + end) / 2;

	if (k == data[mid]){
		if (mid == end){
			res = end;
		}
		else if (data[mid + 1] > k){
			res = mid;
		}
		else{
			res = getLastK(data, k, mid + 1, end);
		}
	}
	else if (k < data[mid]){
		res = getLastK(data, k, start, mid-1);
	}
	else if (k > data[mid]){
		res = getLastK(data, k, mid + 1, end);
	}

	return res;
}

int GetNumberOfK(vector<int> data, int k) {
	int first = getFirstK(data, k, 0, data.size() - 1);
	int last = getLastK(data, k, 0, data.size() - 1);

	if (first == -1 && last == -1){
		return 0;
	}

	return last - first + 1;
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	vector<int> data = {1,3,3,3,3,4,5};
	int k = 2;

	DWORD start, stop;
	start = GetTickCount();
	int res = GetNumberOfK(data, k);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
