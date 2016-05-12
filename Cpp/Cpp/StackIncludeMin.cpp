/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-12

Description: ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>
#include <stack>
#include<assert.h>

using namespace std;

class Solution {
public:
	stack<int> dataStack;
	stack<int> minStack;

	void push(int value) {
		dataStack.push(value);
		if (dataStack.empty() || value < minStack.top()){
			minStack.push(value);
		}
	}
	void pop() {
		assert(dataStack.size() >0);

		if (dataStack.top() == minStack.top()){
			minStack.pop();
		}
		dataStack.pop();
	}
	int top() {
		assert(dataStack.size() >0);
		return dataStack.top();
	}
	int min() {
		assert(minStack.size() >0);
		return minStack.top();
	}
};
