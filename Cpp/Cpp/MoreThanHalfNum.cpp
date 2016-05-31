/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-29

Description: ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
             ��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.size() == 0){
		return 0;
	}

	int res = numbers[0];
	int count = 1;
	for (auto i = 1; i < numbers.size(); i++){
		if (count == 0){
			res = numbers[i];
			count = 1;
		}
		else if (numbers[i] == res){
			count++;
		}
		else{
			count--;
		}
	}

	int times = 0;
	for (auto i = 0; i < numbers.size(); i++){
		if (res == numbers[i]){
			times++;
		}
	}

	if (times <= numbers.size()/2){
		return 0;
	}

	return res;
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	int res = 0;
	vector<int> numbers = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };

	DWORD start, stop;
	start = GetTickCount();
	res = MoreThanHalfNum_Solution(numbers);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}