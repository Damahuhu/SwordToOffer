/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-31

Description: HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
			 ��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
             ����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
             ����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.size() == 0){
		return 0;
	}

	int sum = array[0];
	int res = array[0];

	for (auto i = 1; i < array.size(); i++){
		if (sum > 0){
			sum += array[i];
		}
		else{
			sum = array[i];
		}

		if (res < sum){
			res = sum;
		}
	}

	return res;
}

void PrintRes(int res)
{
	cout << "res: " << res << endl;
}

int main()
{
	vector<int> array = { 6, -3, -2, 7, -15, 1, 2, 2 };

	DWORD start, stop;
	start = GetTickCount();
	int res = FindGreatestSumOfSubArray(array);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}