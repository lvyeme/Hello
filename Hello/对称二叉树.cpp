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
	//�ݹ�
	bool compare(TreeNode* left, TreeNode* right) {
	//�����ų��սڵ�����
		if (left == NULL && right != NULL)return false;
		else if (left != NULL && right == NULL)return false;
		else if (left == NULL && right == NULL) return true;
		//���ų���ֵ��ͬ�����
		else if (left->val != right->val)return false;

		//��ʱ���ǣ����ҽڵ㶼��Ϊ�գ�����ֵ��ͬ���
		bool outside = compare(left->left, right->right);//��������������������
		bool inside = compare(left->left, right->right);//���������ң�����������
		bool isSame = outside && inside;
		return isSame;
	}

	bool isSymmetric(TreeNode* root) {
	
		if (root == NULL)
		{
			return true;
		}return compare(root->left, root->right);
	}
	//��ӡ������ֵ����
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

    // ����һ���򵥵Ķ��������ԳƵ������
    TreeNode* rootSymmetric = new TreeNode(1);
    rootSymmetric->left = new TreeNode(2);
    rootSymmetric->right = new TreeNode(2);
    rootSymmetric->left->left = new TreeNode(3);
    rootSymmetric->left->right = new TreeNode(4);
    rootSymmetric->right->left = new TreeNode(4);
    rootSymmetric->right->right = new TreeNode(3);

    // ��ʾ�Գƶ���������ֵ
    cout << "�Գƶ���������ֵ��" << endl;
    solu.printTree(rootSymmetric);
    cout << endl;

    // ������Ƿ�Գ�
    bool isSymmetric = solu.isSymmetric(rootSymmetric);
    cout << "�Գ����Ƿ�Գƣ�" << (isSymmetric ? "��" : "��") << endl;

    // ������һ�����������ǶԳƵ������
    TreeNode* rootNonSymmetric = new TreeNode(1);
    rootNonSymmetric->left = new TreeNode(2);
    rootNonSymmetric->right = new TreeNode(2);
    rootNonSymmetric->left->right = new TreeNode(3);
    rootNonSymmetric->right->right = new TreeNode(3);

    // ��ʾ�ǶԳƶ���������ֵ
    cout << "�ǶԳƶ���������ֵ��" << endl;
    solu.printTree(rootNonSymmetric);
    cout << endl;

    // ������Ƿ�Գ�
    bool isNonSymmetric = solu.isSymmetric(rootNonSymmetric);
    cout << "�ǶԳ����Ƿ�Գƣ�" << (isNonSymmetric ? "��" : "��") << endl;

    return 0;
}
