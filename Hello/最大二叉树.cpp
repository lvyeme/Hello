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

private:
	//在左闭右开区间[left,right),构造二叉树
	TreeNode* traversal(vector<int>& nums, int left, int right) { 
	
		if (left >= right)return nullptr;

		//分割点下标:macValueIndex
		int maxValueIndex = left;
		for (int i = left + 1; i < right; i++) {
		
			if (nums[i] > nums[maxValueIndex])maxValueIndex = i;
		}
		TreeNode* root = new TreeNode(nums[maxValueIndex]);

		//左闭右开[left,maxValueIndex)
		root->left = traversal(nums, left, maxValueIndex);

		//左闭右开[maxValueIndex + 1 , right)
		root->right = traversal(nums, maxValueIndex + 1, right);

		return root;
	} 

public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	
		return traversal(nums, 0, nums.size());
	}

};

int main() {
	// 创建一个测试用例
	vector<int> nums = { 3, 2, 1, 6, 0, 5 };

	// 创建 Solution 对象
	Solution solution;

	// 构建最大二叉树
	TreeNode* root = solution.constructMaximumBinaryTree(nums);

	// 输出结果
	cout << "构建的最大二叉树的根节点值为：" << root->val << endl;

	return 0;
}

