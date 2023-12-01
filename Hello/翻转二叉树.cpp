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
	//�ݹ�������
	TreeNode* invertTree(TreeNode* root) {
	
		if (root == NULL) return root;
		swap(root->left, root->right);//��
		invertTree(root->left);//��
		invertTree(root->right);//��
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
	// ����һ���򵥵Ķ�����
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	Solution solution;
	TreeNode* invertedRoot = solution.invertTree(root);

	cout << "��ת��Ķ�������\n";
	solution.printTree(invertedRoot);

	return 0;
}