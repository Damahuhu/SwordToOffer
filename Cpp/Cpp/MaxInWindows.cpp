/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-28

Description: ����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
             ���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
			 ���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
			 {[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}��
			 {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
**************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <windows.h>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> res;
	deque<unsigned int> que;

	if (num.size() < size || size == 0){
		return res;
	}

	for (unsigned int i = 0; i < size; i++){
		while (!que.empty() && num[que.back()] <= num[i]){
			que.pop_back();
		}
		que.push_back(i);
	}

	res.push_back(num[que.front()]);

	for (unsigned int i = size; i < num.size(); i++){
		while (!que.empty() && num[que.back()] <= num[i]){
			que.pop_back();
		}

		if (!que.empty() && que.front() < i - size + 1){
			que.pop_front();
		}

		que.push_back(i);
		res.push_back(num[que.front()]);
	}

	return res;
}

void PrintRes(vector<int> res)
{
	for (auto i = 0; i < res.size(); i++){
		cout <<  res[i] << " ";
	}

	cout << endl;
}

int main()
{
	vector<int> num = { 16, 14, 12, 10, 8, 6, 4 };
	unsigned int size = 5;

	DWORD start, stop;
	start = GetTickCount();
	vector<int> res = maxInWindows(num, size);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
