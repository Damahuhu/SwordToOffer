/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-28

Description: 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
             那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
			 那么中位数就是所有数值排序之后中间两个数的平均值。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		size_t totalSize = maxHeap.size() + minHeap.size();
		if (totalSize % 2 == 0){
			maxHeap.push_back(num);
			push_heap(maxHeap.begin(), maxHeap.end(), less<int>());

			minHeap.push_back(maxHeap[0]);
			push_heap(minHeap.begin(), minHeap.end(), greater<int>());

			pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
			maxHeap.pop_back();
		}
		else{
			minHeap.push_back(num);
			push_heap(minHeap.begin(), minHeap.end(), greater<int>());

			maxHeap.push_back(minHeap[0]);
			push_heap(maxHeap.begin(), maxHeap.end(), less<int>());

			pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
			minHeap.pop_back();
		}
	}

	double GetMedian()
	{
		size_t totalSize = maxHeap.size() + minHeap.size();
		if (totalSize == 0){
			return 0;
		}

		double median = 0;
		if (totalSize%2 == 0){
			median = (maxHeap[0] + minHeap[0])/2.0;
		}
		else{
			median = minHeap[0];
		}

		return median;
	}

private:
	vector<int> maxHeap;
	vector<int> minHeap;
};

int main()
{
	return 0;
}
