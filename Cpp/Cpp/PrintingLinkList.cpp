/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-02

Description:输入一个链表，从尾到头打印链表每个节点的值。 
**************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <windows.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {
	}
	void insert(int x){
		ListNode *lv = new ListNode(x);
		ListNode *curNode = this;

		while (curNode->next != NULL){
			curNode = curNode->next;
		}
		curNode->next = lv;
	}
};

vector<int> printListFromTailToHead(struct ListNode* head) {
	std::stack<int> resStack;
	std::vector<int> resVector;

	ListNode* curNode = head;
	while (curNode!=NULL){
		resStack.push(curNode->val);
		curNode = curNode->next;
	}

	while (!resStack.empty()){
		resVector.push_back(resStack.top());
		resStack.pop();
	}

	return resVector;
}

void PrintRes(vector<int> &res){
	for (int i = 0; i < res.size(); i++){
		std::cout << res[i] << " ";
	}

	std::cout << std::endl;
}

int main(){
	ListNode* head = new ListNode(0);
	vector<int> res;
	head->insert(1);
	head->insert(2);
	head->insert(3);
	head->insert(4);
	head->insert(5);

	DWORD start, stop;

	start = GetTickCount();
	res = printListFromTailToHead(head);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}