/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-07

Description: �����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
             ����һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,
			 Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void Reverse(string &str, int start, int end){
	if (start<0 || end >= str.size() || start>=end){
		return;
	}

	while (start < end){
		char tem = str[start];
		str[start] = str[end];
		str[end] = tem;

		start++;
		end--;
	}
}

string LeftRotateString(string str, int n) {
	if (str.empty() || n < 0){
		return str;
	}

	int len = str.size();
	int leftMove = n % (len);

	Reverse(str, 0, leftMove - 1);
	Reverse(str, leftMove, len - 1);
	Reverse(str, 0, len - 1);

	return str;
}

void PrintRes(string res)
{
	std::cout << res.c_str() << std::endl;
}

int main()
{
	string str = "abcXYZdef";
	int n = 2;

	DWORD start, stop;
	start = GetTickCount();
	string res = LeftRotateString(str, n);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
