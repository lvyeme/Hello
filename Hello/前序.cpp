#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	
public:
	vector<int> inorderTraversal(TreeNode* root) {
	
		stack<TreeNode*> st;
		vector<int> result;
		//TreeNode* cur = root;

		if (root == NULL)return result;//�����Ϊ��ֱ�ӷ���
		st.push(root);//�Ѹ��ڵ����ջ
		while (!st.empty())//ֱ��ջΪ��
		{
			TreeNode* node = st.top(); //��ջ��ȡ�����ڵ�Ԫ��
			st.pop();//�����ڵ�
			result.push_back(node->val);//����Ҫ�����������
			if (node->right)st.push(node->right);//�����ҽڵ�
			if (node->left)st.push(node->left);//�ٷ�����ڵ�
		}
		return result;
	}
};

int main() {
	// ����һ���򵥵Ķ�����
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	// ʹ�� Solution ��� preorderTraversal ��������Ԥ�������
	Solution solution;
	vector<int> traversalResult = solution.inorderTraversal(root);

	// ���Ԥ��������Ľ��
	cout << "Preorder Traversal Result:" << endl;
	for (int val : traversalResult) {
		cout << val << " ";
	}
	cout << endl;
}