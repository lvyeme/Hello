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

		int leftValue = sunOfLeftLeaves(root->left);//��
		if (root->left && !root->left->left && !root->left->right)//����������һ����Ҷ�ӵ����
		{
			leftValue = root->left->val;
		}
		int rightValue = sunOfLeftLeaves(root->right);//��
		int sum = leftValue + rightValue;//��
		return sum;
	}
};
