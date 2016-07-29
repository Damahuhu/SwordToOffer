/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-28

Description: 给定一颗二叉搜索树，请找出其中的第k大的结点。
             例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
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
};

TreeNode* KthNode(TreeNode* pRoot, unsigned int &k)
{
	if (pRoot == NULL || k == 0){
		return NULL;
	}

	TreeNode *res = NULL;

	res = KthNode(pRoot->left, k);

	if (res == NULL && k == 1){
		res = pRoot;
	}

	k--;

	if (res == NULL){
		res = KthNode(pRoot->right, k);
	}
	
	return res;
}

int main()
{
	return 0;
}
