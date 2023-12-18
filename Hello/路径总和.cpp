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

class Solution {
private:

public:
	bool traversal(TreeNode* cur, int count) {
	
		if (!cur->left && !cur->right && count == 0)return true;//遇到叶子节点，并计数为0
		if (!cur->left && !cur->right) return false;//遇到叶子节点而没有找到合适的边，直接返回

		if (cur->left)//左 （空节点不便遍历）
			//遇到叶子节点返回true，则直接返回true
		{
			if (traversal(cur->left, count - cur->left->val)) return true;
		}
		if (cur->right)
		{
			if (traversal(cur->right, count - cur->right->val)) return true;
		}
		return false;
	}

	bool hashPathSum(TreeNode* root, int sum) {
	
		if (root == NULL) return false;
		return traversal(root, sum - root->val);
	}
};
int main() {
	Solution solu;

	// 创建一个二叉树
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int sum = 22;

	// 检查二叉树是否具有指定的路径和
	bool result = solu.hashPathSum(root, sum);

	// 输出结果
	cout << "二叉树是否具有路径和 " << sum << ": " << (result ? "是" : "否") << endl;

	return 0;
}
