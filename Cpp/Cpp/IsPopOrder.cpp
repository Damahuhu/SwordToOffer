/*************************************************
Copyright:***

Author: Hao Li

Date: 2016-05-24

Description: 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
             假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
			 但4,3,5,1,2就不可能是该压栈序列的弹出序列。
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