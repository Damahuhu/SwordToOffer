/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-31

Description: ���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
             Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�
			 ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�����
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int NumberOf1(const char *str)
{
	if (str == NULL || *str < '0' || *str > '9' || *str == '\0'){
		return 0;
	}

	int len = strlen(str);
	int first = *str - '0';

	if (len == 1 && first == 0){
		return 0;
	}

	if (len == 1 && first > 1){
		return 1;
	}

	int first1Num = 0;
	int other1Num = 0;
	int recursion1Num = 0;

	if (first > 1){
		first1Num = pow(10, (len - 1) > 0 ? (len - 1) : 0);
	}
	else if (first == 1){
		first1Num = atoi(str + 1) + 1;
	}

	other1Num = first * (len - 1) * pow(10, (len - 2) > 0 ? (len - 2) : 0);

	recursion1Num = NumberOf1(str + 1);

	return (first1Num + other1Num + recursion1Num);
}

int NumberOf1Between1AndN_Solution(int n)
{
	if (n <= 0){
		return 0;
	}

	char str[32];
	sprintf(str, "%d", n);

	return NumberOf1(str);
}

void PrintRes(int res)
{
	cout << "res: " << res << endl;
}

int main()
{ 
	int n = 10000;

	DWORD start, stop;
	start = GetTickCount();
	int res = NumberOf1Between1AndN_Solution(n);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}