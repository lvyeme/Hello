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
	//递归主函数
	TreeNode* invertTree(TreeNode* root) {
	
		if (root == NULL) return root;
		swap(root->left, root->right);//中
		invertTree(root->left);//左
		invertTree(root->right);//右
		return root;
	}

	void printTree(TreeNode* root) {
		if (root == NULL) return;

		queue<TreeNode*> que;
		que.push(root);

		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				cout << node->val << " ";

				if (node->left != NULL) que.push(node->left);
				if (node->right != NULL) que.push(node->right);
			}
			cout << endl;
		}
	}
};

int main() {
	// 创建一个简单的二叉树
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	Solution solution;
	TreeNode* invertedRoot = solution.invertTree(root);

	cout << "反转后的二叉树：\n";
	solution.printTree(invertedRoot);

	return 0;
}