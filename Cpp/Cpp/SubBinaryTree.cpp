/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-12

Description: 输入两颗二叉树A，B，判断B是不是A的子结构。
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

bool Tree1ContainsTree2(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == NULL){
		return true;
	}

	if (pRoot1 == NULL){
		return false;
	}

	if (pRoot1->val != pRoot2->val){
		return false;
	}

	return Tree1ContainsTree2(pRoot1->left, pRoot2->left) && Tree1ContainsTree2(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL || pRoot2 == NULL){
		return false;
	}

	bool res = false;
    
	if (pRoot1->val == pRoot2->val){
		res = Tree1ContainsTree2(pRoot1, pRoot2);
	}
	if (!res){
		res = HasSubtree(pRoot1->left, pRoot2);
	}
	if (!res){
		res = HasSubtree(pRoot1->right, pRoot2);
	}

	return res;
}

void PrintRes(bool res)
{
	if (res){
		std::cout << "yes" << std::endl;
	}
	else{
		std::cout << "no" << std::endl;
	}
}

int main()
{
	TreeNode* pRoot1 = new TreeNode(1);
	TreeNode* pRoot2;

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

	pRoot2 = t4;

	DWORD start, stop;
	start = GetTickCount();
	bool res = HasSubtree(pRoot1, pRoot2);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);
	return 0;
}