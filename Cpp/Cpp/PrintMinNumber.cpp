/*************************************************

Copyright:***

Author:Hao Li

Date:2016-06-30

Description:输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
            例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

string PrintMinNumber(vector<int> numbers) 
{

}

void quick_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int i = left, j = right, target = arr[left];
		while (i < j)
		{
			while (i < j && arr[j] > target)
				j--;
			if (i < j)
				arr[i++] = arr[j];

			while (i < j && arr[i] < target)
				i++;
			if (i < j)
				arr[j] = arr[i];
		}
		arr[i] = target;
		quick_sort(arr, left, i - 1);
		quick_sort(arr, i + 1, right);
	}
}

void sortStr(vector<string> &numbers)
{

}

int compareTwoStr(string &str1, string &str2)
{
	string strA = str1 + str2;
	string strB = str2 + str1;

	return strcmp(strA.c_str(), strB.c_str());
}

void PrintRes(string &res)
{
	std::cout << "res: " << res.c_str() << std::endl;
}

int main()
{
	vector<int> numbers = { 3, 32, 321 };

	DWORD start, stop;
	start = GetTickCount();
	string res = PrintMinNumber(numbers);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
