/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-09

Description: 每年六一儿童节,NowCoder都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为NowCoder的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,
并且拿到NowCoder名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？
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
