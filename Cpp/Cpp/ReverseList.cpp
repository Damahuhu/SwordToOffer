/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-11

Description: 输入一个链表，反转链表后，输出链表的所有元素。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
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

ListNode* ReverseList(ListNode* pHead) {
	if (pHead == NULL){
		return NULL;
	}
	ListNode *currentNode = pHead;
	ListNode *nextNode = pHead->next;
	pHead->next = NULL;

	while (nextNode){
		ListNode *temNode = nextNode->next;
		nextNode->next = currentNode;
		currentNode = nextNode;
		nextNode = temNode;
	}

	return currentNode;
}

void PrintRes(ListNode* node)
{
	if (node != NULL){
		std::cout << "res: " << node->val << std::endl;
	}
}

int main()
{
	ListNode* linkList = new ListNode(1);
	ListNode* res;
	unsigned int k = 5;
	linkList->insert(2);
	linkList->insert(3);
	linkList->insert(4);
	linkList->insert(5);

	DWORD start, stop;
	start = GetTickCount();
	res = ReverseList(linkList);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}