/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-10

Description: 输入一个链表，输出该链表中倒数第k个结点。
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

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL || k == 0){
		return NULL;
	}

	ListNode* firstPtr = pListHead;
	ListNode* secondPtr = pListHead;

	int count = 0;
	while (firstPtr->next != NULL){
		count++;
		firstPtr = firstPtr->next;

		if (count >= k){
			secondPtr = secondPtr->next;
		}
	}

	if (count < k-1){
		return NULL;
	}

	return secondPtr;
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
	res = FindKthToTail(linkList, k);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}