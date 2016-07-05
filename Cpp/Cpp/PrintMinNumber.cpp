/*************************************************

Copyright:***

Author:Hao Li

Date:2016-06-30

Description:����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
            ������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int compareTwoStr(string str1, string str2)
{
	string strA = str1 + str2;
	string strB = str2 + str1;

	return strcmp(strA.c_str(), strB.c_str());
}

void sortStr(vector<int> &numbers, int first, int last)
{
	if (numbers.size() == 0){
		return;
	}

	if (first < last){
		int i = first;
		int j = last;
		int targetNum = numbers[first];
		char target[32];
		char strI[32];
		char strJ[32];
		sprintf(target, "%d", numbers[first]);
		sprintf(strI, "%d", numbers[i]);
		sprintf(strJ, "%d", numbers[j]);

		while (i < j){
			sprintf(strJ, "%d", numbers[j]);
			while (i < j && compareTwoStr(strJ, target) >= 0){
				j--;
				//memset(strJ, 0, sizeof(strJ) / sizeof(char));
				sprintf(strJ, "%d", numbers[j]);
			}

			if (i < j){
				numbers[i] = numbers[j];
			}

			sprintf(strI, "%d", numbers[i]);
			while (i < j && compareTwoStr(strI, target) <= 0){
				i++;
				//memset(strI, 0, sizeof(strI) / sizeof(char));
				sprintf(strI, "%d", numbers[i]);
			}

			if (i < j){
				numbers[j] = numbers[i];
			}
		}

		numbers[i] = targetNum;
		sortStr(numbers, first, i - 1);
		sortStr(numbers, i + 1, last);
	}
}

string PrintMinNumber(vector<int> numbers)
{
	sortStr(numbers, 0, numbers.size() - 1);

	string res = "";
	for (auto i = 0; i < numbers.size(); i++){
		char str[32];
		sprintf(str, "%d", numbers[i]);
		res = res + str;
	}

	return res;
}

void PrintRes(string &res)
{
	std::cout << "res: " << res.c_str() << std::endl;
}

int main()
{
	vector<int> numbers = { 2,4,3,6,1,5,8,7,9 };

	DWORD start, stop;
	start = GetTickCount();
	string res = PrintMinNumber(numbers);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
