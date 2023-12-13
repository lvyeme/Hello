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
	
		//�� ����Ϊ���һ���ڵ�ҲҪ���뵽path��
		path.push_back(node->val);//��Ϊ��ǰ���������Ҫ�ȴ����нڵ㣬���нڵ��������Ҫ��¼·���ϵĽڵ�
		if (node->left == NULL && node->right == NULL) {
			string sPath;
			for (int i = 0; i < path.size() - 1; i++)//��path���¼��·��תΪstring��ʽ
			{
				sPath += to_string(path[i]);
				sPath += "->";
			}
			sPath += to_string(path[path.size() - 1]);//��¼���һ���ڵ㣨Ҷ�ӽڵ㣩
			result.push_back(sPath);
			return;
		}
		if (node->left)
		{
			trevsal(node->left, path, result);
			path.pop_back();//����
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

	// ����һ���򵥵Ķ�����
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);

	// ��ȡ���������дӸ���Ҷ�ӽڵ��·��
	vector<string> paths = solu.binaryTreePaths(root);

	// �������·��
	cout << "����·����" << endl;
	for (string path : paths) {
		cout << path << endl;
	}

	return 0;
}