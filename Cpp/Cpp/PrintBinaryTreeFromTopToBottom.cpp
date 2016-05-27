/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-24

Description: 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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

vector<int> PrintFromTopToBottom(TreeNode *root) 
{
	vector<int> res;
	queue<TreeNode *> nodeQueue;

	if (root != NULL){
		nodeQueue.push(root);
	}
	
	while (!nodeQueue.empty()){
		TreeNode *node = nodeQueue.front();
		res.push_back(node->val);
		nodeQueue.pop();

		if (node->left != NULL){
			nodeQueue.push(node->left);
		}
		if (node->right != NULL){
			nodeQueue.push(node->right);
		}
	}

	return res;
}

void RrintRes(vector<int> &res)
{
	for (auto i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << endl;
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
	vector<int> res = PrintFromTopToBottom(pRoot1);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	RrintRes(res);

	return 0;
}