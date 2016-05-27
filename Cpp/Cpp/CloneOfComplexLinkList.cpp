/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-27

Description: 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>
#include <queue>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL){
		return NULL;
	}

	//insert clone node after each node
	RandomListNode *currentNode = pHead;
	while (currentNode != NULL){
		RandomListNode *insertNode = new RandomListNode(currentNode->label);
		insertNode->next = currentNode->next;
		currentNode->next = insertNode;

		currentNode = insertNode->next;
	}

	//find random node of each clone node
	currentNode = pHead;
	while (currentNode != NULL){
		RandomListNode *insertNode = currentNode->next;

		if (currentNode->random != NULL){
			insertNode->random = currentNode->random->next;
		}

		currentNode = insertNode->next;
	}

	//get final RandomListNode
	RandomListNode *newHead = pHead->next;
	RandomListNode *originalCurNode = newHead->next;
	RandomListNode *newCurNode = newHead;
	pHead->next = originalCurNode;

	while (originalCurNode != NULL){
		newCurNode->next = originalCurNode->next;
		newCurNode = newCurNode->next;

		originalCurNode->next = newCurNode->next;
		originalCurNode = originalCurNode->next;
	}

	return newHead;
}

int main()
{
	RandomListNode* pHead = new RandomListNode(0);
	RandomListNode* node1 = new RandomListNode(1);
	RandomListNode* node2 = new RandomListNode(2);
	RandomListNode* node3 = new RandomListNode(3);
	RandomListNode* node4 = new RandomListNode(4);
	RandomListNode* node5 = new RandomListNode(5);

	pHead->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	pHead->random = node3;
	node3->random = node5;

	DWORD start, stop;
	start = GetTickCount();
	Clone(pHead);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	return 0;
}