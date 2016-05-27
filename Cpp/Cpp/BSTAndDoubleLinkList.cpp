/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-27

Description: 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}

	void addLeftTree(TreeNode *left){
		this->left = left;
	}

	void addRightTree(TreeNode *right){
		this->right = right;
	}
};

void Convert(TreeNode* pRootOfTree, TreeNode** lastNode){
	if (pRootOfTree == NULL){
		return;
	}

	if (pRootOfTree->left != NULL){
		Convert(pRootOfTree->left, lastNode);
	}

	if ((*lastNode) != NULL){
		pRootOfTree->left = *lastNode;
		(*lastNode)->right = pRootOfTree;
	}

	(*lastNode) = pRootOfTree;

	if (pRootOfTree->right != NULL){
		Convert(pRootOfTree->right, lastNode);
	}
}


TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* lastNode = NULL;

	Convert(pRootOfTree, &lastNode);
	if (lastNode == NULL){
		return NULL;
	}

	TreeNode* firstNode = lastNode;

	while (firstNode->left != NULL){
		firstNode = firstNode->left;
	}

	return firstNode;
}

void RrintRes(TreeNode* node)
{
	TreeNode * curNode = node;
	while (curNode != NULL){
		cout << curNode->val << " ";

		curNode = curNode->right;
	}

	cout << endl;
}

int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);
	TreeNode* t7 = new TreeNode(7);
	TreeNode* t8 = new TreeNode(8);

	t5->addLeftTree(t3);
	t5->addRightTree(t7);

	t3->addLeftTree(t2);
	t3->addRightTree(t4);

	t7->addLeftTree(t6);
	t7->addRightTree(t8);

	DWORD start, stop;
	start = GetTickCount();
	TreeNode *node = Convert(t5);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	RrintRes(node);

	return 0;
}