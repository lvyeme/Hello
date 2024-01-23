#include <iostream>
#include <vector>
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
	TreeNode* search(TreeNode* root, int val) {
	
		if (root == NULL || root->val == val) return root;
		TreeNode* result = NULL;
		if (root->val > val)result = search(root->left, val);
		if (root->val < val)result = search(root->right, val);
		return result;
	}

    TreeNode* searshBST(TreeNode* root, int val) {
        while (root != NULL)
        {
            if (root->val > val)root = root->left;
            else if (root->val < val)root = root->right;
            else return root;
        }
        return NULL;
    }
};

int main() {
    // 创建一颗二叉搜索树
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // 创建 Solution 对象
    Solution solution;

    // 调用 search 方法查找节点值为 3 的节点
    int targetValue = 4;
    TreeNode* resultNode = solution.search(root, targetValue);
    TreeNode* result = solution.searshBST(root, targetValue);
    // 输出结果
    if (resultNode != NULL) {
        cout << "找到节点值为 " << targetValue << " 的节点" << endl;
    }
    else {
        cout << "未找到节点值为 " << targetValue << " 的节点" << endl;
    }

    // 输出结果
    if (result != NULL) {
        cout << "找到节点值为 " << targetValue << " 的节点" << endl;
    }
    else {
        cout << "未找到节点值为 " << targetValue << " 的节点" << endl;
    }
    return 0;
}
