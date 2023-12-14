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

	int findBottomlLeftValue(TreeNode* root) {
	
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		int result = 0;
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop();
				if (i == 0) result = node->val;//��¼���һ�е�һ��Ԫ��
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return result;
	}
};
int main() {
	Solution solu;

	// ����һ��������
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->left->left = new TreeNode(7);

	// �ҳ������½ǵ�ֵ
	int result = solu.findBottomlLeftValue(root);

	// ������
	cout << "�����½ǵ�ֵΪ: " << result << endl;

	return 0;
}

