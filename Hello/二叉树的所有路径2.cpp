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

class Solution {
private:
	void trevsal(TreeNode* node, vector<int>& path, vector<string>& result) {
	
		//中 ，因为最后一个节点也要加入到path中
		path.push_back(node->val);//因为是前序遍历，需要先处理中节点，，中节点就是我们要记录路径上的节点
		if (node->left == NULL && node->right == NULL) {
			string sPath;
			for (int i = 0; i < path.size() - 1; i++)//将path里记录的路径转为string格式
			{
				sPath += to_string(path[i]);
				sPath += "->";
			}
			sPath += to_string(path[path.size() - 1]);//记录最后一个节点（叶子节点）
			result.push_back(sPath);
			return;
		}
		if (node->left)
		{
			trevsal(node->left, path, result);
			path.pop_back();//回溯
		}
		if (node->right)
		{
			trevsal(node->right, path, result);
			path.pop_back();
		}
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
	
		vector<string> result;
		vector<int> path;
		if (root == NULL)return result;
		trevsal(root, path, result);
		return result;
	}
};

int main() {
	Solution solu;

	// 创建一个简单的二叉树
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);

	// 获取二叉树所有从根到叶子节点的路径
	vector<string> paths = solu.binaryTreePaths(root);

	// 输出所有路径
	cout << "所有路径：" << endl;
	for (string path : paths) {
		cout << path << endl;
	}

	return 0;
}