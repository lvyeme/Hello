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
	int sunOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		if (root->left == NULL && root->right == NULL)return 0;

		int leftValue = sunOfLeftLeaves(root->left);//左
		if (root->left && !root->left->left && !root->left->right)//左子树就是一个左叶子的情况
		{
			leftValue = root->left->val;
		}
		int rightValue = sunOfLeftLeaves(root->right);//右
		int sum = leftValue + rightValue;//中
		return sum;
	}
};

int main() {
	// 创建一颗二叉树
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	// 创建 Solution 对象
	Solution solution;

	// 调用 sumOfLeftLeaves 方法计算左叶子节点的和
	int result = solution.sunOfLeftLeaves(root);

	// 输出结果
	cout << "左叶子节点的和为: " << result << endl;

	return 0;
}
