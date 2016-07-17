/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-12

Description: ��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ���
             ��'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
			 �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬
			 ������"aa.a"��"ab*a"����ƥ��
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL){
		return false;
	}
    
	if (*str == '\0' && *pattern == '\0'){
		return true;
	}
    
	if (*str != '\0' && *pattern == '\0'){
		return false;
	}

	if (*(pattern + 1) == '*'){
		if (*str == *pattern  || (*pattern == '.'&&*str != '\0')){
			return match(str + 1, pattern + 2) || match(str + 1, pattern) || match(str, pattern + 2);
		}
		else{
			return match(str, pattern + 2);
		}
	}

	if (*str == *pattern || (*pattern == '.'&&*str != '\0')){
		return match(str+1, pattern+1);
	}

	return false;
}

void PrintRes(bool res)
{
	if (res){
		cout << "Yes!" << endl;
	}
	else{
		cout << "No!" << endl;
	}
}

int main()
{
	//char* str = "aa.a";
	//char* pattern = "ab*a";

	char* str = "aaa";
	char* pattern = "ab*ac*a";

	DWORD start, stop;
	start = GetTickCount();
	bool res = match(str, pattern);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
