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
private:
	vector<int> vec;
	void traversal(TreeNode* root) {
		if (root == NULL)return;
		traversal(root->left);
		vec.push_back(root->val);
		traversal(root->right);
	}
public:
	bool isValidBST(TreeNode* root) {
	
		vec.clear();
		traversal(root);
		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] <= vec[i - 1])return false;
		}
		return true;
	}

};