/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-22

Description: 一个链表中包含环，请找出该链表的环的入口结点。
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
};

int GetLenOfRing(ListNode* pHead){
	if (pHead == NULL){
		return 0;
	}

	ListNode* first = pHead;
	ListNode* second = pHead->next;

	while (first != NULL && second !=NULL){
		if (first == second){
			break;
		}

		first = first->next;
		second = second->next;

		if (second != NULL){
			second = second->next;
		}
		else{
			return 0;
		}
	}

	if (first == NULL || second == NULL){
		return 0;
	}

	int res = 0;
	do{
		first = first->next;
		res++;
	} while (first != second);

	return res;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	int lenOfRing = GetLenOfRing(pHead);
	if (lenOfRing == 0){
		return NULL;
	}

	ListNode* first = pHead;
	ListNode* second = pHead;

	for (int i = 0; i < lenOfRing; i++){
		first = first->next;
	}

	while (first != second){
		first = first->next;
		second = second->next;
	}

	return first;
}

void PrintRes(ListNode* node)
{
	if (node != NULL){
		cout << "res: " << node->val << endl;
	}
	else{
		cout << "NULL!" << endl;
	}
}

int main()
{
	ListNode* pHead;
	DWORD start, stop;
	start = GetTickCount();
	ListNode* res = EntryNodeOfLoop(pHead);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
