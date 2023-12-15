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
