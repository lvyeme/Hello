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
	//������ҿ�����[left,right),���������
	TreeNode* traversal(vector<int>& nums, int left, int right) { 
	
		if (left >= right)return nullptr;

		//�ָ���±�:macValueIndex
		int maxValueIndex = left;
		for (int i = left + 1; i < right; i++) {
		
			if (nums[i] > nums[maxValueIndex])maxValueIndex = i;
		}
		TreeNode* root = new TreeNode(nums[maxValueIndex]);

		//����ҿ�[left,maxValueIndex)
		root->left = traversal(nums, left, maxValueIndex);

		//����ҿ�[maxValueIndex + 1 , right)
		root->right = traversal(nums, maxValueIndex + 1, right);

		return root;
	} 

public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	
		return traversal(nums, 0, nums.size());
	}

};

int main() {
	// ����һ����������
	vector<int> nums = { 3, 2, 1, 6, 0, 5 };

	// ���� Solution ����
	Solution solution;

	// ������������
	TreeNode* root = solution.constructMaximumBinaryTree(nums);

	// ������
	cout << "���������������ĸ��ڵ�ֵΪ��" << root->val << endl;

	return 0;
}

