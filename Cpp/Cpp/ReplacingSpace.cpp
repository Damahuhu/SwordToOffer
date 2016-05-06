/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-02

Description:��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void replaceSpace(char *str, int length) {
	int strLen = 0;//�ַ�������
	int spaceLen = 0;//�ո��ַ�����

	for (int i = 0; i < length; i++){
		if (str[i] == ' '){
			spaceLen++;
		}
		else if (str[i] == '\0'){
			break;
		}
		strLen++;
	}

	int newStrLen = strLen + 2 * spaceLen;//�滻����ַ�������
	if (length < newStrLen + 1){
		return;
	}

	char *pt1 = str + strLen;//ָ��old strβ��
	char *pt2 = str + newStrLen;//ָ��new strβ��

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