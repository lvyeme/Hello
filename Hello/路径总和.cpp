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
	bool traversal(TreeNode* cur, int count) {
	
		if (!cur->left && !cur->right && count == 0)return true;//����Ҷ�ӽڵ㣬������Ϊ0
		if (!cur->left && !cur->right) return false;//����Ҷ�ӽڵ��û���ҵ����ʵıߣ�ֱ�ӷ���

		if (cur->left)//�� ���սڵ㲻�������
			//����Ҷ�ӽڵ㷵��true����ֱ�ӷ���true
		{
			if (traversal(cur->left, count - cur->left->val)) return true;
		}
		if (cur->right)
		{
			if (traversal(cur->right, count - cur->right->val)) return true;
		}
		return false;
	}

	bool hashPathSum(TreeNode* root, int sum) {
	
		if (root == NULL) return false;
		return traversal(root, sum - root->val);
	}
};
int main() {
	Solution solu;

	// ����һ��������
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int sum = 22;

	// ���������Ƿ����ָ����·����
	bool result = solu.hashPathSum(root, sum);

	// ������
	cout << "�������Ƿ����·���� " << sum << ": " << (result ? "��" : "��") << endl;

	return 0;
}
