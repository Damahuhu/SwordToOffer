/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-09

Description: 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

//int NumberOf1(int n) {
//	int count = 0;
//	unsigned int a = 1;
//
//	while (a){
//		int b = a & n;
//		if (b){
//			std::cout << "b: " << b << std::endl;
//			count++;
//		}
//
//		a = a << 1;
//	}
//
//	return count;
//}

int NumberOf1(int n) {
	int count = 0;

	while (n){
		count++;
		n = (n - 1) & n;
	}

	return count;
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	int res = 0;
	int n = -8;

	DWORD start, stop;
	start = GetTickCount();
	res = NumberOf1(n);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	//char a = 127;
	//char b = a << 1;
	//cout << (int)b << endl;

	PrintRes(res);
	return 0;
}