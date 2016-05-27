/*************************************************
Copyright:***

Author:Hao Li

Date:2016-05-27

Description: 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
             路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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

vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector<vector<int> > res;

	if (root != NULL){
		if (root->left == NULL && root->right == NULL && root->val == expectNumber){
			vector<int> tem;
			tem.push_back(expectNumber);
			res.push_back(tem);
		}
		else if (root->val < expectNumber){
			vector<vector<int> > leftRes = FindPath(root->left, expectNumber - root->val);
			vector<vector<int> > rightRes = FindPath(root->right, expectNumber - root->val);

			//combine
			for (int i = 0; i < leftRes.size(); i++){
				vector<int> tem;
				tem.push_back(root->val);
				for (int k = 0; k < leftRes[i].size(); k++){
					tem.push_back(leftRes[i][k]);
				}

				res.push_back(tem);
			}

			for (int i = 0; i < rightRes.size(); i++){
				vector<int> tem;
				tem.push_back(root->val);
				for (int k = 0; k < rightRes[i].size(); k++){
					tem.push_back(rightRes[i][k]);
				}
				res.push_back(tem);
			}
		}
	}

	return res;
}

void RrintRes(vector<vector<int> > &res)
{
	for (auto i = 0; i < res.size(); i++){
		const vector<int> &tem = res[i];
		for (auto k = 0; k < tem.size(); k++){
			cout << tem[k] << " ";
		}
		cout << endl;
	}
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
	vector<vector<int> > res = FindPath(pRoot1, 8);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	RrintRes(res);

	return 0;
}