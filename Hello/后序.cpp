#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
	vector<int> inorderTraversal(TreeNode* root) {

		stack<TreeNode*> st;
		vector<int> result;
		TreeNode* cur = root;

		if (root == NULL) return result;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);
			if (node->left) st.push(node->left);
			if (node->right) st.push(node->right);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main() {
	// 创建一个简单的二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	// 使用 Solution 类的 preorderTraversal 函数进行预订序遍历
	Solution solution;
	vector<int> traversalResult = solution.inorderTraversal(root);

	// 输出预订序遍历的结果
	cout << "Preorder Traversal Result:" << endl;
	for (int val : traversalResult) {
		cout << val << " ";
	}
	cout << endl;
}