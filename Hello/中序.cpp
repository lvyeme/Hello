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
		TreeNode* cur = root;
		while (cur != NULL && !st.empty())
		{
			if (cur != NULL) {//�ڵ㲻Ϊ�հѽڵ����ջ��
				st.push(cur);
				cur = cur->left;//�ȴ�����ڵ�
			}
			else
			{
				cur = st.top();//��һ���ڵ㵯��
				st.pop();//����
				result.push_back(cur->val);//�������ڵ��ֵ����������
				cur = cur->right;//�����ҽڵ�
			}
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