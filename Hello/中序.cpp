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
		while (cur != NULL && !st.empty())
		{
			if (cur != NULL) {//节点不为空把节点放入栈中
				st.push(cur);
				cur = cur->left;//先处理左节点
			}
			else
			{
				cur = st.top();//第一个节点弹出
				st.pop();//弹出
				result.push_back(cur->val);//将弹出节点的值放入数组中
				cur = cur->right;//处理右节点
			}
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