/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-26

Description: 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
             第三行按照从左到右的顺序打印，其他行以此类推。
**************************************************/

#include <iostream>
#include <vector>
#include <stack>
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

	std::stack<TreeNode*> stack1;
	std::stack<TreeNode*> stack2;
	stack1.push(pRoot);

	bool flag = true;

	int curCount = 1;
	int nextCount = 0;

	vector<int> row;
	while (!stack1.empty() || !stack2.empty()){
		if (flag){
			while (!stack1.empty()){
				TreeNode* node = stack1.top();
				row.push_back(node->val);
				stack1.pop();

				if (node->left != NULL){
					stack2.push(node->left);
					nextCount++;
				}

				if (node->right != NULL){
					stack2.push(node->right);
					nextCount++;
				}
			}

			if (!row.empty()){
				res.push_back(row);
				row.clear();
			}
			
			flag = !flag;
		}

		if (!flag){
			while (!stack2.empty()){
				TreeNode* node = stack2.top();
				row.push_back(node->val);
				stack2.pop();

				if (node->right != NULL){
					stack1.push(node->right);
					nextCount++;
				}

				if (node->left != NULL){
					stack1.push(node->left);
					nextCount++;
				}
			}

			if (!row.empty()){
				res.push_back(row);
				row.clear();
			}

			flag = !flag;
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
