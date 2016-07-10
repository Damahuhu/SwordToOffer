/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-10

Description: ����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
             ����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

vector<int> multiply(const vector<int>& A)
{
	vector<int> res;
	int len = A.size();

	int tem1 = 1;
	for (int i = 0; i < A.size(); i++){
		if (i == 0){
			res.push_back(tem1);
			continue;
		}

		tem1 *= A[i - 1];
		res.push_back(tem1);
	}
	
	int tem2 = 1;
	for (int i = A.size() - 1; i >= 0; i--){
		if (i == A.size() - 1){
			continue;
		}

		tem2 *= A[i + 1];
		res[i] *= tem2;
	}

	return res;
}

void PrintRes(vector<int> &res)
{
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5};

	DWORD start, stop;
	start = GetTickCount();
	vector<int> res = multiply(A);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
