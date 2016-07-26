/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-26

Description: 请实现一个函数，用来判断一颗二叉树是不是对称的。
             注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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

bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL && pRoot2 == NULL){
		return true;
	}
	if (pRoot1 == NULL || pRoot2 == NULL){
		return false;
	}
	if (pRoot1->val != pRoot2->val){
		return false;
	}

	return isSymmetrical(pRoot1->left, pRoot2->right) &&
		isSymmetrical(pRoot1->right, pRoot2->left);
}

bool isSymmetrical(TreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

void PrintRes(bool res)
{
	switch (res){
	case true:
		cout << "yes!" << endl;
		break;
	case false:
		cout << "no!" << endl;
		break;
	}
}

int main()
{
	TreeNode* pRoot;

	DWORD start, stop;
	start = GetTickCount();
	bool res = isSymmetrical(pRoot);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
