#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
	int getDpth(TreeNode* node) {
	
		if (node == NULL) return 0;
		int leftDepth = getDpth(node->left);
		int rightDepth = getDpth(node->right);
		if (leftDepth != NULL && rightDepth == NULL)
		{
			return 1 + leftDepth;
		}
		if (leftDepth == NULL && rightDepth != NULL)
		{
			return 1 + rightDepth;
		}
		int result = 1 + min(leftDepth, rightDepth);
		return result;
	}

	int minDepth(TreeNode* root) {

		return getDpth(root);
	}
};

int main() {
	Solution solu;

	// 创建一个简单的二叉树
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	// 计算树的最小深度
	int minDepth = solu.minDepth(root);
	cout << "二叉树的最小深度为：" << minDepth << endl;

	return 0;
}

