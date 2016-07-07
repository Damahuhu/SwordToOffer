/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-06

Description: 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
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

bool IsBalanced(TreeNode* pRoot, int &depth){
	if (pRoot == NULL){
		depth = 0;
		return true;
	}

	int leftDepth = 0;
	int rightDepth = 0;
	bool left = IsBalanced(pRoot->left, leftDepth);
	bool right = IsBalanced(pRoot->right, rightDepth);

	if (left && right){
		if (abs(leftDepth - rightDepth) <= 1){
			depth = leftDepth < rightDepth ? (rightDepth+1) : (leftDepth+1);
			return true;
		}
	}

	return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	int depth = 0;

	return IsBalanced(pRoot, depth);
}

void PrintRes(int res)
{
	std::cout << "res: " << res << std::endl;
}

int main()
{
	TreeNode* pRoot;

	DWORD start, stop;
	start = GetTickCount();
	int res = IsBalanced_Solution(pRoot);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
