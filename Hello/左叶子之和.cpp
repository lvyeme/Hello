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

int main() {
	// ����һ�Ŷ�����
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	// ���� Solution ����
	Solution solution;

	// ���� sumOfLeftLeaves ����������Ҷ�ӽڵ�ĺ�
	int result = solution.sunOfLeftLeaves(root);

	// ������
	cout << "��Ҷ�ӽڵ�ĺ�Ϊ: " << result << endl;

	return 0;
}
