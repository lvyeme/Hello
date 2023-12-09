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

	int contNodes(TreeNode* node) {
	
		if (node == NULL) return 0;
		TreeNode* left = node->left;
		TreeNode* right = node->right;
		int leftDepth = 0 , rightDepth = 0;
		while (left)
		{
			left = left->left;
			leftDepth++;
		}
		while (right)
		{
			right = right->right;
			rightDepth++;
		}
		if (leftDepth == rightDepth)
		{
			return (2 << leftDepth) - 1;
		}
		int leftNum = contNodes(node->left);//左
		int rightNum = contNodes(node->right);//右
		int result = leftNum + rightNum + 1;//中


		return result;
	}
};

int main() {
	Solution solu;

	// 创建一个简单的二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	// 计算二叉树的节点个数
	int nodeCount = solu.contNodes(root);
	cout << "二叉树的节点个数为：" << nodeCount << endl;

	return 0;
}

