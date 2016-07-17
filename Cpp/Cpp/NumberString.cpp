/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-12

Description: 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
             例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
			 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void scanDigits(char** string){
	while ((**string) != '\0' && (**string) <= '9' && (**string) >= '0'){
		(*string)++;
	}
}

bool isScientificNotation(char* string)
{
	if ((*string) == '+' || (*string) == '-'){
		string++;
	}

	if ((*string) == '\0'){
		return false;
	}

	scanDigits(&string);


	if ((*string) == '\0'){
		return true;
	}

	return false;
}

bool isNumeric(char* string)
{
	if (string == NULL){
		return false;
	}

	if ((*string) == '+' || (*string) == '-'){
		string++;
	}

	if ((*string) == '\0'){
		return false;
	}

	scanDigits(&string);

	if ((*string) == '.'){
		string++;
		scanDigits(&string);
	}

	if ((*string) == 'e' || (*string) == 'E'){
		string++;
		return isScientificNotation(string);
	}

	if ((*string) == '\0'){
		return true;
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
	char* string = "123.45e+6";

	DWORD start, stop;
	start = GetTickCount();
	bool res = isNumeric(string);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
