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
		//2.后序遍历数组最后一个元素，就是当前的中间节点
		int rootValue = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(rootValue);

		//叶子节点
		if (postorder.size() == 1)return root;

		//3.找切割点
		int delimiterIndex;
		for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
			if (inorder[delimiterIndex] == rootValue)break;
		}
		//4.切割中序数组，得到 中序左数组和中序右数组
		int delimiterInedx;
		for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
		{
			if (inorder[delimiterIndex] == rootValue)break;
		}


		//左闭右开区间[0,delimiterIdex]
		vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
		//[delimiterIdex + 1 , end]
		vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

		//postorder 舍弃末尾元素，因为这个元素就是中间节点，已经用过了
		postorder.resize(postorder.size() - 1);
		//5.切割后序数字，得到，后序左数组和后序右数组
		//左闭右开，
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

// 层序遍历，用于验证构建的二叉树是否正确
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

	// 输入中序遍历和后序遍历数组
	vector<int> inorder = { 9, 3, 15, 20, 7 };
	vector<int> postorder = { 9, 15, 7, 20, 3 };

	// 构建二叉树
	TreeNode* root = solution.buildTree(inorder, postorder);

	// 层序遍历验证结果
	cout << "层序遍历结果: ";
	levelOrder(root);

	return 0;
}

