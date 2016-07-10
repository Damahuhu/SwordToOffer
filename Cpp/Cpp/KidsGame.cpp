/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-09

Description: ÿ����һ��ͯ��,NowCoder����׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�
HF��ΪNowCoder������Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:
����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
ÿ�κ���m���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,
��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,
�����õ�NowCoder����ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��������������,�ĸ�С���ѻ�õ������Ʒ�أ�
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int LastRemaining_Solution(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1){
		return -1;
	}

	int res = 0;
	if (n == 1){
		return res;
	}
	else if (n > 1){
		int preRes = LastRemaining_Solution(n - 1, m);
		res = (preRes + m)%n;
	}

	return res;
}

void PrintRes(int res)
{
	cout << "res:" << res << endl;
}

int main()
{
	unsigned int n = 7;
	unsigned int m = 4;

	DWORD start, stop;
	start = GetTickCount();
	int res = LastRemaining_Solution(n, m);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
