/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-11

Description: 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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

//loop method
//ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//{
//	if (pHead1 == NULL){
//		return pHead2;
//	}
//
//	if (pHead2 == NULL){
//		return pHead1;
//	}
//
//	ListNode* ln1 = pHead1;
//	ListNode* ln2 = pHead2;
//	ListNode* ptr = NULL;
//
//	if (ln1->val < ln2->val){
//		ptr = ln1;
//		ln1 = ln1->next;
//	}
//	else{
//		ptr = ln2;
//		ln2 = ln2->next;
//	}
//
//	ListNode* merged_ln = ptr;
//
//	while (ln1 != NULL && ln2 != NULL){
//		if (ln1->val < ln2->val){
//			ptr->next = ln1;
//			ptr = ptr->next;
//			ln1 = ln1->next;
//		}
//		else{
//			ptr->next = ln2;
//			ptr = ptr->next;
//			ln2 = ln2->next;
//		}
//	}
//
//	if (ln1 == NULL){
//		ptr->next = ln2;
//	}
//
//	if (ln2 == NULL){
//		ptr->next = ln1;
//	}
//
//	return merged_ln;
//}

//recursion method
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL){
		return pHead2;
	}

	if (pHead2 == NULL){
		return pHead1;
	}

	ListNode* ln1 = pHead1;
	ListNode* ln2 = pHead2;
	ListNode* mergeln = NULL;

	if (ln1->val < ln2->val){
		mergeln = ln1;
		mergeln->next = Merge(ln1->next, ln2);
	}
	else{
		mergeln = ln2;
		mergeln->next = Merge(ln1, ln2->next);
	}

	return mergeln;
}

void PrintRes(ListNode* node)
{
	ListNode *curNode = node;
	while (curNode != NULL){
		std::cout << curNode->val << " ";
		curNode = curNode->next;
	}

	std::cout << std::endl;
}

int main()
{
	ListNode* linkList1 = new ListNode(1);
	ListNode* linkList2 = new ListNode(2);
	ListNode* res;
	unsigned int k = 5;
	linkList1->insert(2);
	linkList1->insert(4);
	linkList1->insert(7);
	linkList2->insert(2);
	linkList2->insert(4);
	linkList2->insert(8);

	DWORD start, stop;
	start = GetTickCount();
	res = Merge(linkList1, linkList2);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}