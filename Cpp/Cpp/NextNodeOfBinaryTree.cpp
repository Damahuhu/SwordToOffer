/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-26

Description: 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
             注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};


TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL){
		return NULL;
	}

	if (pNode->right != NULL){
		TreeLinkNode *nextNode = pNode->right;
		while (nextNode->left != NULL){
			nextNode = nextNode->left;
		}
		return nextNode;
	}
	else{
		TreeLinkNode *nextNode = pNode->next;
		if (nextNode != NULL && nextNode->left == pNode){
			return nextNode;
		}
		else if (nextNode != NULL && nextNode->right == pNode){
			while (nextNode != NULL){
				TreeLinkNode *prNode = nextNode->next;
				if (prNode != NULL && prNode->left == nextNode){
					return prNode;
				}
				nextNode = prNode;
			}
		}
	}

	return NULL;
}

void PrintRes(TreeLinkNode* res)
{
	if (res == NULL){
		cout << "NULL!" << endl;
	}
	else{
		cout << "res: " << res->val << endl;
	}
}

int main()
{
	TreeLinkNode* pNode;

	DWORD start, stop;
	start = GetTickCount();
	TreeLinkNode* res = GetNext(pNode);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
