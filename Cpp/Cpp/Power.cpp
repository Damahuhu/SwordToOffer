/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-09

Description: 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

bool doubleEqual(double a, double b){
	if (a - b < 1e-7 && a - b > -1e-7){
		return true;
	}
    
	return false;
}

double Power(double base, int exponent) {
	if (doubleEqual(base, 0) && exponent < 0){
		return 0;
	}
	double res = 1.0;
	int times = std::abs(exponent);

	for (int i = 0; i < times; i++){
		res *= base;
	}

	if (exponent < 0){
		res = 1.0 / res;
	}

	return res;
}

void PrintRes(double res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	double res = 0;
	double base = 0;
	int exponent = -2;

	DWORD start, stop;
	start = GetTickCount();
	res = Power(base, exponent);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}