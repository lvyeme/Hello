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
	//递归
	bool compare(TreeNode* left, TreeNode* right) {
	//首先排除空节点的情况
		if (left == NULL && right != NULL)return false;
		else if (left != NULL && right == NULL)return false;
		else if (left == NULL && right == NULL) return true;
		//再排除数值不同的情况
		else if (left->val != right->val)return false;

		//此时就是，左右节点都不为空，且数值相同情况
		bool outside = compare(left->left, right->right);//左子树：左，右子树：右
		bool inside = compare(left->left, right->right);//左子树：右，右子树：左
		bool isSame = outside && inside;
		return isSame;
	}

	bool isSymmetric(TreeNode* root) {
	
		if (root == NULL)
		{
			return true;
		}return compare(root->left, root->right);
	}
	//打印树的数值函数
	void printTree(TreeNode* root) {
		if (root == NULL) return;
		queue<TreeNode*> que;
		que.push(root);

		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				cout << node->val << " ";
				if (node->left != NULL) que.push(node->left);
				if (node->right != NULL) que.push(node->right);
			}
			cout << endl;
		}
	}
};
int main() {
    Solution solu;

    // 创建一个简单的二叉树（对称的情况）
    TreeNode* rootSymmetric = new TreeNode(1);
    rootSymmetric->left = new TreeNode(2);
    rootSymmetric->right = new TreeNode(2);
    rootSymmetric->left->left = new TreeNode(3);
    rootSymmetric->left->right = new TreeNode(4);
    rootSymmetric->right->left = new TreeNode(4);
    rootSymmetric->right->right = new TreeNode(3);

    // 显示对称二叉树的数值
    cout << "对称二叉树的数值：" << endl;
    solu.printTree(rootSymmetric);
    cout << endl;

    // 检查树是否对称
    bool isSymmetric = solu.isSymmetric(rootSymmetric);
    cout << "对称树是否对称：" << (isSymmetric ? "是" : "否") << endl;

    // 创建另一个二叉树（非对称的情况）
    TreeNode* rootNonSymmetric = new TreeNode(1);
    rootNonSymmetric->left = new TreeNode(2);
    rootNonSymmetric->right = new TreeNode(2);
    rootNonSymmetric->left->right = new TreeNode(3);
    rootNonSymmetric->right->right = new TreeNode(3);

    // 显示非对称二叉树的数值
    cout << "非对称二叉树的数值：" << endl;
    solu.printTree(rootNonSymmetric);
    cout << endl;

    // 检查树是否对称
    bool isNonSymmetric = solu.isSymmetric(rootNonSymmetric);
    cout << "非对称树是否对称：" << (isNonSymmetric ? "是" : "否") << endl;

    return 0;
}
