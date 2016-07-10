/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-07

Description: ����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S��
             ����ж�����ֵĺ͵���S������������ĳ˻���С�ġ� 

			 ��Ӧÿ�����԰����������������С���������
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
