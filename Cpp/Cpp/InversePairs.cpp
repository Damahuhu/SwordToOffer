/*************************************************

Copyright:***

Author:Hao Li

Date:2016-07-05

Description: 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
             输入一个数组，求出这个数组中的逆序对的总数。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int Merge(vector<int> &data, vector<int> &tem, int start, int end) {
	if (data.size() != tem.size()){
		return 0;
	}

	if (start >= end){
		return 0;
	}

	int count = 0;

	int mid = (start + end) / 2;
	
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end){
		if (data[i] > data[j]){
			tem[k++] = data[j++];
			count += (mid + 1 - i);
		}
		else{
			tem[k++] = data[i++];
		}
	}

	while (i <= mid){
		tem[k++] = data[i++];
	}

	while (j <= end){
		tem[k++] = data[j++];
	}

	for (int m = start; m <= end; m++){
		data[m] = tem[m];
	}

	return count;
}

int MergeSort(vector<int> &data, vector<int> &tem, int start, int end) {
	if (data.size() != tem.size()){
		return 0;
	}

	if (start >= end){
		return 0;
	}

	int mid = (start + end) / 2;

	int left = MergeSort(data, tem, start, mid);
	int right = MergeSort(data, tem, mid + 1, end);
	int count = Merge(data, tem, start, end);

	return left + right + count;
}

int InversePairs(vector<int> data) {
	vector<int> tem(data.size());
	int res = MergeSort(data, tem, 0, data.size() - 1);

	for (int i = 0; i < data.size(); i++){
		cout << data[i] << endl;
	}

	return res;
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	vector<int> data = {1,2,3,4,7,6,5};

	DWORD start, stop;
	start = GetTickCount();
	int res = InversePairs(data);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
