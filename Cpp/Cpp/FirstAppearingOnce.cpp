/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-14

Description: ��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
             ���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
             ���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"�� 

			 �����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class Solution
{
public:
	Solution(){
		for (int i = 0; i < 256; i++){
			letters[i] = -1;
			index = 0;
		}
	}

	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (letters[ch] == -1){
			letters[ch] = index;
		}
		else if (letters[ch] >= 0){
			letters[ch] = -2;
		}

		index++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int minIndex = 256;
		char ch = '#';
		for (int i = 0; i < 256; i++){
			if (letters[i] >= 0){
				if (minIndex > letters[i]){
					ch = (char)i;
					minIndex = letters[i];
				}
			}
		}

		return ch;
	}

private:
	char letters[256];
	int index;
};

void PrintRes(char res)
{
	cout << "res: " << res << endl;
}

int main()
{
	Solution solution;
	solution.Insert('g');
	solution.Insert('o');
	solution.Insert('o');
	solution.Insert('g');
	solution.Insert('l');
	solution.Insert('e');

	DWORD start, stop;
	start = GetTickCount();
	char res = solution.FirstAppearingOnce();
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
