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
    // ����һ�Ŷ���������
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // ���� Solution ����
    Solution solution;

    // ���� search �������ҽڵ�ֵΪ 3 �Ľڵ�
    int targetValue = 4;
    TreeNode* resultNode = solution.search(root, targetValue);
    TreeNode* result = solution.searshBST(root, targetValue);
    // ������
    if (resultNode != NULL) {
        cout << "�ҵ��ڵ�ֵΪ " << targetValue << " �Ľڵ�" << endl;
    }
    else {
        cout << "δ�ҵ��ڵ�ֵΪ " << targetValue << " �Ľڵ�" << endl;
    }

    // ������
    if (result != NULL) {
        cout << "�ҵ��ڵ�ֵΪ " << targetValue << " �Ľڵ�" << endl;
    }
    else {
        cout << "δ�ҵ��ڵ�ֵΪ " << targetValue << " �Ľڵ�" << endl;
    }
    return 0;
}
