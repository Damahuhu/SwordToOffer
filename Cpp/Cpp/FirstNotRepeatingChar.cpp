/*************************************************

Copyright:***

Author:Hao Li

Date:2016-07-05

Description: ��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ���λ�á�
             ��Ϊ�մ�������-1��λ��������0��ʼ
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int FirstNotRepeatingChar(string str){
	if (str.length() == 0){
		return -1;
	}

	int times[256];
	memset(times, 0, sizeof(int) * 256);

	for (auto it = str.begin(); it != str.end(); it++){
		times[(int)(*it)]++;
	}

	int pos = 0;
	for (auto it = str.begin(); it != str.end(); it++){
		if (times[(int)(*it)] == 1){
			break;
		}

		pos++;
	}

	if (pos >= str.length()){
		return -1;
	}

	return pos;
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	string str = "abaccdeff";

	DWORD start, stop;
	start = GetTickCount();
	int res = FirstNotRepeatingChar(str);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
