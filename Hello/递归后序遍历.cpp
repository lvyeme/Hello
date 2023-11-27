#include <iostream>
#include <vector>

using namespace std;

//定义二叉树节点
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	//二叉树递归辅助函数
	void traversal(TreeNode* cur,vector<int>& vec) {
		if (cur == nullptr)
		{
			return;
		}
		traversal(cur->left, vec);
		traversal(cur->right, vec);
		vec.push_back(cur->val);
	}

	vector<int> backTraversal(TreeNode* root) {
	
		vector<int> result;
		traversal(root,result);
		return result;
	}
};

int main() {

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(7);

	Solution solu;
	vector<int> result;
	result = solu.backTraversal(root);

	cout << "输出结果" << endl;
	for (int val : result)
	{
		cout << val << " ";
	}
	cout << endl;

	return 0;
}

