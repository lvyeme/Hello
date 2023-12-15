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
		//��
		if (node->left) {
		
			depth++;
			traversal(node->left,depth);
			depth--;//����
		}
		//��
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

	// ����һ��������
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->left->left = new TreeNode(7);

	// �ҳ������½ǵ�ֵ
	int result = solu.findBottomLeftValue(root);

	// ������
	cout << "�����½ǵ�ֵΪ: " << result << endl;

	return 0;
}