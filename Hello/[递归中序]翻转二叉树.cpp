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
	//递归函数
	TreeNode* invertTree(TreeNode* root) {
	
		if(root == NULL) return root;
		invertTree(root->left);//左
		swap(root->left, root->right);//中
		invertTree(root->left);//这里以就需要遍历左孩子，因为中间节点已经被翻转了
		return root;
	}

	//打印树函数
	void printTree(TreeNode* root) {
	
		if (root == NULL) return;
		queue<TreeNode*> que;
		que.push(root);

		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				cout << node->val << " ";
				if (node->left != NULL)que.push(node->left);
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


	Solution solu;
	TreeNode* result = solu.invertTree(root);

	cout << "翻转二叉树" << endl;
	solu.printTree(result);

	return 0;

}