/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-29

Description: 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
             例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 结果请按字母顺序输出。
**************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

void Permutation(string prefix, string str, vector<string> &res) {
	if (str.empty()){
		res.push_back(prefix);
		return;
	}

	for (int i = 0; i < str.size(); i++){
		if (i != 0 && str[0] == str[i]){
			continue;
		}

		char tem_char = str[0];
		str[0] = str[i];
		str[i] = tem_char;

		string newPrefix = prefix + str[0];
		string newStr = str.substr(1);
		Permutation(newPrefix, newStr, res);
	}
}

vector<string> Permutation(string str) {
	vector<string> res;
	if (str.empty()){
		return res;
	}

	sort(str.begin(), str.end());
	Permutation("", str, res);

	return res;
}


void PrintRes(vector<string> &res)
{
	for (auto i = 0; i < res.size(); i++){
		std::cout << res[i].c_str() << std::endl;
	}
}

int main()
{
	DWORD start, stop;
	start = GetTickCount();
	vector<string> res = Permutation("aab");
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}