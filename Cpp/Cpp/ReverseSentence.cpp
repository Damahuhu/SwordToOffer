/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-07

Description: ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
             ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
			 ���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
			 ��ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
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

string ReverseSentence(string str) {
	int len = str.size();
	Reverse(str, 0, len - 1);

	int start = 0;
	for (int i = 0; i < len; i++){
		if (str[i] == ' '){
			Reverse(str, start, i - 1);
			start = i + 1;
		}
	}

	Reverse(str, start, len - 1);

	return str;
}

void PrintRes(string res)
{
	std::cout << res.c_str() << std::endl;
}

int main()
{
	string str = "World!";

	DWORD start, stop;
	start = GetTickCount();
	string res = ReverseSentence(str);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
