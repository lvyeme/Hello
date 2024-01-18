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

	//5.�и�������֣��õ�������������ͺ���������

	//6.
	root->left = traversal();
	root->right = traversal();
	
	return root;
}

