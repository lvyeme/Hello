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
	//
	int getdepth(TreeNode* node) {
	
		if (node == NULL) return 0;
		int leftdepth = getdepth(node->left);//��
		int rigthdepth = getdepth(node->right);//��
		int depth = 1 + max(leftdepth, rigthdepth);//��
		return depth;
	}
	int maxDepth(TreeNode* root) {
	
		return getdepth(root);
	}
};

int main() {
	Solution solu;

	// ����һ���򵥵Ķ�����
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	// ��������������
	int maxDepth = solu.maxDepth(root);
	cout << "��������������Ϊ��" << maxDepth << endl;

	return 0;
}
