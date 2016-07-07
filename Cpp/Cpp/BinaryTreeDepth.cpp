/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-06

Description: ����һ�ö����������������ȡ�
			 �Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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

int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL){
		return 0;
	}

	int leftDepth = TreeDepth(pRoot->left);
	int rightDepth = TreeDepth(pRoot->right);

	int depth = 0;
	if (leftDepth > rightDepth){
		depth = leftDepth + 1;
	}
	else{
		depth = rightDepth + 1;
	}

	return depth;
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
	int res = TreeDepth(pRoot);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
