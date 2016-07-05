/*************************************************

Copyright:***

Author:Hao Li

Date:2016-07-05

Description: 输入两个链表，找出它们的第一个公共结点。
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

	void insert(int val){
		ListNode *node = new ListNode(val);
		ListNode *cur = this;

		while (cur->next != NULL){
			cur = cur->next;
		}

		cur->next = node;
	}
}; 

ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
	int len1 = 0;
	int len2 = 0;

	ListNode *cur1 = pHead1;
	ListNode *cur2 = pHead2;

	while (cur1 != NULL){
		cur1 = cur1->next;
		len1++;
	}

	while (cur2 != NULL){
		cur2 = cur2->next;
		len2++;
	}

	int delta = 0;
	if (len1 < len2){
		delta = len2 - len1;
		cur1 = pHead2;
		cur2 = pHead1;
	}
	else{
		delta = len1 - len2;
		cur1 = pHead1;
		cur2 = pHead2;
	}
	
	for (int i = 0; i < delta; i++){
		cur1 = cur1->next;
	}
	
	while (cur1!=NULL){
		if (cur1 == cur2){
			return cur1;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	return NULL;
}

void PrintRes(ListNode* node)
{
	if (node!=NULL){
		std::cout << "res: " << node->val << std::endl;
	}
	else{
		std::cout << "res: " << NULL << std::endl;
	}
}

int main()
{
	ListNode *pHead1;
	ListNode *pHead2;

	DWORD start, stop;
	start = GetTickCount();
	ListNode* node = FindFirstCommonNode(pHead1, pHead2);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(node);

	return 0;
}
