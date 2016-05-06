/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-02

Description:请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void replaceSpace(char *str, int length) {
	int strLen = 0;//字符串长度
	int spaceLen = 0;//空格字符个数

	for (int i = 0; i < length; i++){
		if (str[i] == ' '){
			spaceLen++;
		}
		else if (str[i] == '\0'){
			break;
		}
		strLen++;
	}

	int newStrLen = strLen + 2 * spaceLen;//替换后的字符串长度
	if (length < newStrLen + 1){
		return;
	}

	char *pt1 = str + strLen;//指向old str尾部
	char *pt2 = str + newStrLen;//指向new str尾部

	for (int i = 0; i <= strLen; i++){
		if ((*pt1) == ' '){
			(*pt2) = '0';
			pt2--;
			(*pt2) = '2';
			pt2--;
			(*pt2) = '%';
		}
		else{
			(*pt2) = (*pt1);
		}
		pt1--;
		pt2--;
	}
}

void PrintRes(char *res){
	std::cout << "res: " << res << std::endl;
}

int main(){
	char str[100] = "We are happy.";
	int length = 100;

	DWORD start, stop;

	start = GetTickCount();
	replaceSpace(str, length);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(str);

	return 0;
}