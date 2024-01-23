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
	
		if (t1 == NULL)return t2;//���t1Ϊ�գ��ϲ�֮�����t2
		if (t2 == NULL)return t1;//���t2Ϊ�գ��ϲ�֮�����t1
		//�޸���t1����ֵ�ṹ
		t1->val += t2->val;//��
		t1->left = mergeTrees(t1->left, t2->left);//��
		t1->right = mergeTrees(t1->right, t2->right);//��
		return t1;
	}
};

// ǰ�����������������Ľṹ
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " "; // ��
    preorderTraversal(root->left); // ��
    preorderTraversal(root->right); // ��
}

int main() {
    Solution solution;

    // ���������򵥵Ķ�����
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);

    // �ϲ�����������
    TreeNode* mergedTree = solution.mergeTrees(t1, t2);

    // ����ϲ���Ķ������ṹ
    cout << "�ϲ���Ķ�����ǰ��������: ";
    preorderTraversal(mergedTree);

    return 0;
}



