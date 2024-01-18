#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
	//1.
	if (postorder.size() == 0) return NULL;
	//2.后序遍历数组最后一个元素，就是当前的中间节点
	int rootValue = postorder[postorder.size() - 1];
	TreeNode* root = new TreeNode(rootValue);

	//叶子节点
	if (postorder.size() == 1)return root;

	//3.找切割点
	int delimiterIndex;
	for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
		if (inorder[delimiterIndex] == rootValue)break;
	}
	//4.切割中序数组，得到 中序左数组和中序右数组

	//5.切割后序数字，得到，后序左数组和后序右数组

	//6.
	root->left = traversal();
	root->right = traversal();
	
	return root;
}

