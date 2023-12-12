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

	void traversal(TreeNode* cur, string path, vector<string>& result) {
	
		path += to_string(cur->val);
		if (cur->left == NULL && cur->right == NULL)
		{
			result.push_back(path);
			return;
		}
		if (cur->left)traversal(cur->left, path + "->", result);
		if (cur->right)traversal(cur->right, path + "->", result);
	}
public:
	vector<string>binaryTreePaths(TreeNode* root) {
	
		vector<string> result;
		string path;
		if (root == NULL)return result;
		traversal(root, path, result);
		return result;
	}
};

int main() {
	Solution solu;

	// 创建一个简单的二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);

	// 获取二叉树所有从根到叶子节点的路径
	vector<string> paths = solu.binaryTreePaths(root);

	// 输出所有路径
	cout << "所有路径：" << endl;
	for (string path : paths) {
		cout << path << endl;
	}

	return 0;
}
