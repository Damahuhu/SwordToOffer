/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-26

Description: 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
**************************************************/

#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int> > Print(TreeNode* pRoot) {
	vector<vector<int> > res;
	if (pRoot == NULL){
		return res;
	}

	std::queue<TreeNode*> nodes;
	nodes.push(pRoot);

	int curCount = 1;
	int nextCount = 0;

	vector<int> row;
	while (!nodes.empty()){
		TreeNode* node = nodes.front();
		row.push_back(node->val);
		nodes.pop();

		curCount--;

		if (node->left != NULL){
			nodes.push(node->left);
			nextCount++;
		}

		if (node->right != NULL){
			nodes.push(node->right);
			nextCount++;
		}

		if (curCount == 0){
			res.push_back(row);
			row.clear();

			curCount = nextCount;
			nextCount = 0;
		}
	}

	return res;
}

void PrintRes(vector<vector<int> >& res)
{
	for (int i = 0; i < res.size(); i++){
		vector<int> tem = res[i];
		for (int j = 0; j < tem.size(); i++){
			cout << tem[j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	TreeNode* pRoot;

	DWORD start, stop;
	start = GetTickCount();
	vector<vector<int> > res = Print(pRoot);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	PrintRes(res);

	return 0;
}
