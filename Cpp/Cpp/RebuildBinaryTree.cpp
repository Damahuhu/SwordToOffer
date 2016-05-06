/*************************************************

Copyright:***

Author:Hao Li

Date:2016-05-02

Description:输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。。 
**************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <windows.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
	if (pre.size() == 0 || in.size() == 0){
		return NULL;
	}

	int root_value = pre[0];
	TreeNode *tn = new TreeNode(root_value);

	vector<int> pre_left;
	vector<int> in_left;
	vector<int> pre_right;
	vector<int> in_right;
	
	int count_left = 0;
	for (int i = 0; i < in.size(); i++){
		if (in[i] == root_value){
			break;
		}

		count_left++;
	}

	for (int i = 1; i < pre.size(); i++){
		if (i <= count_left){
			pre_left.push_back(pre[i]);
		}
		else{
			pre_right.push_back(pre[i]);
		}
	}

	for (int i = 0; i < in.size(); i++){
		if (i < count_left){
			in_left.push_back(in[i]);
		}
		else if (i > count_left){
			in_right.push_back(in[i]);
		}
	}

	tn->left = reConstructBinaryTree(pre_left, in_left);
	tn->right = reConstructBinaryTree(pre_right, in_right);

	return tn;
}

int main(){
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> in = { 4, 7, 2, 1, 5, 3, 8, 6 };

	DWORD start, stop;

	start = GetTickCount();
	TreeNode* tn = reConstructBinaryTree(pre, in);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	return 0;
}