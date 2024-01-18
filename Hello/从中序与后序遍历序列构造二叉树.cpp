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
class Solution
{
private:

	TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
		//1.
		if (postorder.size() == 0) return NULL;
		//2.��������������һ��Ԫ�أ����ǵ�ǰ���м�ڵ�
		int rootValue = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(rootValue);

		//Ҷ�ӽڵ�
		if (postorder.size() == 1)return root;

		//3.���и��
		int delimiterIndex;
		for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
			if (inorder[delimiterIndex] == rootValue)break;
		}
		//4.�и��������飬�õ� ���������������������
		int delimiterInedx;
		for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
		{
			if (inorder[delimiterIndex] == rootValue)break;
		}


		//����ҿ�����[0,delimiterIdex]
		vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
		//[delimiterIdex + 1 , end]
		vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

		//postorder ����ĩβԪ�أ���Ϊ���Ԫ�ؾ����м�ڵ㣬�Ѿ��ù���
		postorder.resize(postorder.size() - 1);
		//5.�и�������֣��õ�������������ͺ���������
		//����ҿ���
		vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
		//[leftIoder.size(),end]
		vector<int> rightPostoder(postorder.begin() + leftInorder.size(), postorder.end());
		//6.
		root->left = traversal(leftInorder, leftPostorder);
		root->right = traversal(rightInorder, rightPostoder);

		return root;
	}

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postoder) {
		if (inorder.size() == 0 || postoder.size() == 0) return NULL;
		return traversal(inorder, postoder);
	}

};

// ���������������֤�����Ķ������Ƿ���ȷ
void levelOrder(TreeNode* root) {
	if (!root) return;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* node = q.front();
		q.pop();
		cout << node->val << " ";

		if (node->left) q.push(node->left);
		if (node->right) q.push(node->right);
	}
}

int main() {
	Solution solution;

	// ������������ͺ����������
	vector<int> inorder = { 9, 3, 15, 20, 7 };
	vector<int> postorder = { 9, 15, 7, 20, 3 };

	// ����������
	TreeNode* root = solution.buildTree(inorder, postorder);

	// ���������֤���
	cout << "����������: ";
	levelOrder(root);

	return 0;
}

