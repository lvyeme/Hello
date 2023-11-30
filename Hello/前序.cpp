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
		//TreeNode* cur = root;

		if (root == NULL)return result;//如果树为空直接返回
		st.push(root);//把根节点放入栈
		while (!st.empty())//直至栈为空
		{
			TreeNode* node = st.top(); //从栈中取出顶节点元素
			st.pop();//弹出节点
			result.push_back(node->val);//放入要输出的数组中
			if (node->right)st.push(node->right);//放入右节点
			if (node->left)st.push(node->left);//再放入左节点
		}
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