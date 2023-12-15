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
	int maxDepth = INT_MIN;
	int result;
	void traversal(TreeNode* node, int depth) {
	
		if (node->left == NULL && node->right == NULL)
		{
			if (depth > maxDepth) {
			
				maxDepth = depth;
				result = node->val;
			}
			return;
		}
		//左
		if (node->left) {
		
			depth++;
			traversal(node->left,depth);
			depth--;//回溯
		}
		//右
		if (node->right)
		{
			depth++;
			traversal(node->right, depth);
			depth--;
		}
		return;
	}

	int findBottomLeftValue(TreeNode* root) {
	
		traversal(root, 0);
		return result;
	}
};

int main() {
	Solution solu;

	// 创建一个二叉树
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->left->left = new TreeNode(7);

	// 找出最左下角的值
	int result = solu.findBottomLeftValue(root);

	// 输出结果
	cout << "最左下角的值为: " << result << endl;

	return 0;
}