/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-02

Description:��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
			����һ���ǵݼ����е�һ����ת�������ת�������СԪ�ء�
            ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {

}

void PrintRes(int res){
	std::cout << "res: " << res << std::endl;
}

int main(){
	vector<int> rotateArray = { 3, 4, 5, 1, 2 };
	int res = 0;

	DWORD start, stop;
	start = GetTickCount();
	res = minNumberInRotateArray(rotateArray);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}