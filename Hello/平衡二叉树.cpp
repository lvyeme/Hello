#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x) ,left(NULL), right(NULL) {}
};

class Solution {
public:
	int getHight(TreeNode* node) {
	
		if (node == NULL) return 0;
		int leftHight = getHight(node->left);
		if (leftHight == -1) return -1;
		int rightHight = getHight(node->right);
		if (rightHight == -1) return -1;
		int result;
		if (abs(leftHight - rightHight) > 1)
		{
			result = -1;
		}
		else
		{
			result = 1 + max(leftHight, rightHight);
		}
		return result;
	}

};

int main() {
	Solution solu;

	// ����һ���򵥵�ƽ�������
	TreeNode* rootBalanced = new TreeNode(1);
	rootBalanced->left = new TreeNode(2);
	rootBalanced->right = new TreeNode(3);
	rootBalanced->left->left = new TreeNode(4);
	rootBalanced->left->right = new TreeNode(5);
	rootBalanced->right->left = new TreeNode(6);
	rootBalanced->right->right = new TreeNode(7);

	// ����ƽ��������ĸ߶�
	int heightBalanced = solu.getHight(rootBalanced);
	cout << "ƽ��������ĸ߶�Ϊ��" << heightBalanced << endl;

	// ����һ����ƽ��Ķ�����
	TreeNode* rootUnbalanced = new TreeNode(1);
	rootUnbalanced->left = new TreeNode(2);
	rootUnbalanced->right = new TreeNode(3);
	rootUnbalanced->left->left = new TreeNode(4);
	rootUnbalanced->left->left->left = new TreeNode(5);

	// ���Է�ƽ��������ĸ߶�
	int heightUnbalanced = solu.getHight(rootUnbalanced);
	cout << "��ƽ��������ĸ߶�Ϊ��" << heightUnbalanced << endl;

	return 0;
}
