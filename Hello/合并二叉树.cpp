#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	
		if (t1 == NULL)return t2;//如果t1为空，合并之后就是t2
		if (t2 == NULL)return t1;//如果t2为空，合并之后就是t1
		//修改了t1的数值结构
		t1->val += t2->val;//中
		t1->left = mergeTrees(t1->left, t2->left);//左
		t1->right = mergeTrees(t1->right, t2->right);//右
		return t1;
	}
};

// 前序遍历，用于输出树的结构
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " "; // 中
    preorderTraversal(root->left); // 左
    preorderTraversal(root->right); // 右
}

int main() {
    Solution solution;

    // 创建两个简单的二叉树
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);

    // 合并两个二叉树
    TreeNode* mergedTree = solution.mergeTrees(t1, t2);

    // 输出合并后的二叉树结构
    cout << "合并后的二叉树前序遍历结果: ";
    preorderTraversal(mergedTree);

    return 0;
}



