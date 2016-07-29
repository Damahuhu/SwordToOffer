/*************************************************
Copyright:***

Author:Hao Li

Date:2016-07-28

Description: 请实现两个函数，分别用来序列化和反序列化二叉树。这里没有规定序列化的方式。
**************************************************/

#include <iostream>
#include <vector>
#include <string>
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

char* Serialize(TreeNode *root) {
	if (root == NULL){
		return "$";
	}

	string str = to_string(root->val);
	str.append(",");
	char* leftStr = Serialize(root->left);
	char* rightStr = Serialize(root->right);

	char *res = new char[str.length() + strlen(leftStr) + strlen(rightStr)];
	strcpy(res, str.c_str());
	strcat(res, leftStr);
	strcat(res, rightStr);

	return res;
}

TreeNode* DeserializeTree(char *&str) {
	if (strlen(str) <= 0|| *str == '$'){
		str++;
		return NULL;
	}

	int val = 0;
	while (*str != ','){
		val = (*str - '0') + val*10;
		str++;
	}
	str++;

	TreeNode* res = new TreeNode(val);
	res->left = DeserializeTree(str);
	res->right = DeserializeTree(str);

	return res;
}

TreeNode* Deserialize(char *str) {
	return DeserializeTree(str);
}

int main()
{
	return 0;
}
