/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-12

Description: ���������Ķ�����������任ΪԴ�������ľ��� 
��������:
�������ľ����壺Դ������
    8
  /   \
 6    10
/ \   / \
5  7  9 11
���������
    8
  /   \
 10    6
/ \    / \
11 9  7  5
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

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

void Mirror(TreeNode *pRoot) {
	if (pRoot == NULL){
		return;
	}

	TreeNode *temNode = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temNode;

	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

int main()
{
	TreeNode* pRoot1 = new TreeNode(1);

	TreeNode* t1 = new TreeNode(2);
	TreeNode* t2 = new TreeNode(3);
	TreeNode* t3 = new TreeNode(4);
	TreeNode* t4 = new TreeNode(5);
	TreeNode* t5 = new TreeNode(6);
	TreeNode* t6 = new TreeNode(7);
	t4->addLeftTree(t5);
	t4->addRightTree(t6);

	t2->addLeftTree(t4);
	t2->addRightTree(t3);

	pRoot1->addLeftTree(t2);
	pRoot1->addRightTree(t1);

	DWORD start, stop;
	start = GetTickCount();
	Mirror(pRoot1);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	return 0;
}