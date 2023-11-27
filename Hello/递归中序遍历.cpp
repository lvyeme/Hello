#include <iostream>
#include <vector>

using namespace std;

//定义二叉树节点
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
	void traversal(TreeNode* cur,vector<int>& vec) {//辅助函数递归遍历二叉树
		if (cur == nullptr)
		{
			return;
		}
		traversal(cur->left, vec);
		vec.push_back(cur->val);
		traversal(cur->right, vec);
	}

	//主函数
	vector<int>midTraversal(TreeNode* root) {
	
		vector<int> result;
		traversal(root, result);
		return result;
	}

	//数组创建二叉树
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
	// 创建一个简单的二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	// 使用 Solution 类的 preorderTraversal 函数进行预订序遍历
	Solution solution;
	vector<int> traversalResult = solution.midTraversal(root);

	// 输出预订序遍历的结果
	cout << "Preorder Traversal Result:" << endl;
	for (int val : traversalResult) {
		cout << val << " ";
	}
	cout << endl;

	//使用数组创建二叉树
	/*vector<int> arr = {1, 2, 3, 4, 5, 6, 7}; // -1表示NULL
	Solution solution;

	TreeNode* root = solution.createBinaryTree(arr, 0);

	// 使用 Solution 类的 preorderTraversal 函数进行预订序遍历
	vector<int> traversalResult = solution.preorderTraversal(root);

	// 输出预订序遍历的结果
	cout << "Preorder Traversal Result:" << endl;
	for (int val : traversalResult) {
		cout << val << " ";
	}
	cout << endl;*/

	return 0;
}

