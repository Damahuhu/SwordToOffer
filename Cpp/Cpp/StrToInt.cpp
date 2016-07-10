/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-10

Description: ��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯����
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int StrToInt(string str) {
	int len = str.length();
	int res = 0;

	int factor = 1;
	for (int i = len - 1; i >= 0; i--){
		if (i == 0){
			if (str[i] == '+'){
				return res;
			}
			else if (str[i] == '-'){
				return -res;
			}
		}

		int tem = str[i] - '0';
		if (tem > 9){
			return 0;
		}

		res += tem * factor;
		factor *= 10;
	}

	return res;
}

void PrintRes(int res)
{
	cout << "res:" << res << endl;
}

int main()
{
	string str = "-3a56";

	DWORD start, stop;
	start = GetTickCount();
	int res = StrToInt(str);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
