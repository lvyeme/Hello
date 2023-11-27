#include <iostream>
#include <vector>

using namespace std;

//����������ڵ�
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	void traversal(TreeNode* cur,vector<int>& vec) {//���������ݹ����������
		if (cur == nullptr)
		{
			return;
		}
		traversal(cur->left, vec);
		vec.push_back(cur->val);
		traversal(cur->right, vec);
	}

	//������
	vector<int>midTraversal(TreeNode* root) {
	
		vector<int> result;
		traversal(root, result);
		return result;
	}

	//���鴴��������
	TreeNode* createBinaryTree(vector<int>& arr, int index) {
		if (index >= arr.size() || arr[index] == -1) {
			return NULL;
		}

		TreeNode* root = new TreeNode(arr[index]);
		root->left = createBinaryTree(arr, 2 * index + 1);
		root->right = createBinaryTree(arr, 2 * index + 2);
		return root;
	}
};

int main(){
	// ����һ���򵥵Ķ�����
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	// ʹ�� Solution ��� preorderTraversal ��������Ԥ�������
	Solution solution;
	vector<int> traversalResult = solution.midTraversal(root);

	// ���Ԥ��������Ľ��
	cout << "Preorder Traversal Result:" << endl;
	for (int val : traversalResult) {
		cout << val << " ";
	}
	cout << endl;

	//ʹ�����鴴��������
	/*vector<int> arr = {1, 2, 3, 4, 5, 6, 7}; // -1��ʾNULL
	Solution solution;

	TreeNode* root = solution.createBinaryTree(arr, 0);

	// ʹ�� Solution ��� preorderTraversal ��������Ԥ�������
	vector<int> traversalResult = solution.preorderTraversal(root);

	// ���Ԥ��������Ľ��
	cout << "Preorder Traversal Result:" << endl;
	for (int val : traversalResult) {
		cout << val << " ";
	}
	cout << endl;*/

	return 0;
}

