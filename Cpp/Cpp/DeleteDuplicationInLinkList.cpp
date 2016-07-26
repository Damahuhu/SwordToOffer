/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-25

Description: ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
             ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL){
		return NULL;
	}

	ListNode* curNode = pHead;
	ListNode* preNode = NULL;

	while (curNode != NULL){
		ListNode* nextNode = curNode->next;
		if (nextNode != NULL && nextNode->val == curNode->val){
			int val = curNode->val;
			ListNode* dulNode = curNode;

			while (dulNode != NULL && dulNode->val == val){
				nextNode = dulNode->next;
				delete dulNode;
				dulNode = nextNode;
			}
			curNode = nextNode;

			if (preNode != NULL){
				preNode->next = curNode;
			}
			else{
				pHead = curNode;
			}
		}
		else{
			preNode = curNode;
			curNode = nextNode;
		}
	}

	return pHead;
}

void PrintRes(ListNode* res)
{
	ListNode *pt = res;
	while (pt != NULL){
		cout << pt->val;
		pt = pt->next;
		if (pt != NULL){
			cout << "->";
		}
	}

	cout << "endl";
}

int main()
{
	ListNode* pHead;

	DWORD start, stop;
	start = GetTickCount();
	ListNode* res = deleteDuplication(pHead);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
