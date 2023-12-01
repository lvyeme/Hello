#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
	vector<vector<int>> levelOder(TreeNode* root) {
		queue<TreeNode*>que;
		if (root != NULL)que.push(root);
		vector<vector<int>> result;

		while (!que.empty())
		{
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();//ȡ����ǰ��ĵ�һ��Ԫ��
				que.pop();
				vec.push_back(node->val);
				if (node->left)que.push(node->left);
				if (node->right)que.push(node->right);
			}
			result.push_back(vec);
		}
		return result;
	}
};

int main() {
	Solution solution;

	// ����һ�ö�����
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	// ʹ�� levelOder ������ȡ�������Ĳ���������
	vector<vector<int>> levelOrderResult = solution.levelOder(root);

	// �������������
	cout << "[" << endl;
	for (vector<int>& level : levelOrderResult) {
		cout << "    [";
		for (int val : level) {
			cout << val;
			if (&val != &level.back()) {
				cout << ",";
			}
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;

	return 0;
}
