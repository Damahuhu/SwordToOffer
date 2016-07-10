/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-07

Description: 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
             同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
			 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
			 正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
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
