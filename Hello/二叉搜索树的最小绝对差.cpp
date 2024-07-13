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
		traversal(root->left);
		vec.push_back(root->val);//将二搜索叉树转为有序数组
		traversal(root->right);
	}

public:
	int getMinimumDifference(TreeNode* root) {
		vec.clear();
		traversal(root);
		if (vec.size() < 2)return 0;
		int result = INT_MAX;
	}
};



int main() {


}

