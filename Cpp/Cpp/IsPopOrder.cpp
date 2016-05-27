/*************************************************
Copyright:***

Author: Hao Li

Date: 2016-05-24

Description: ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
             ����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
			 ��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	if (pushV.size() == 0 || popV.size() == 0){
		return false;
	}

	stack<int> temStack;

	int count = 0;
	for (int i = 0; i < pushV.size(); i++){
		temStack.push(pushV[i]);

		while (!temStack.empty() && temStack.top() == popV[count]){
			temStack.pop();
			count++;
		}
	}

	if (count == popV.size()){
		return true;
	}

	return false;
}

void PrintRes(bool res)
{
	if (res){
		std::cout << "yes" << std::endl;
	}
	else{
		std::cout << "no" << std::endl;
	}
}

int main()
{
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 4, 5, 3, 2, 1 };

	DWORD start, stop;
	start = GetTickCount();
	bool res = IsPopOrder(pushV, popV);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}