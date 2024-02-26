#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
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
	void searchBST(TreeNode* cur, unordered_map<int, int>& map){
		//前序遍历
		if (cur == NULL) return;
		map[cur->val]++;//统计元素频率
		searchBST(cur->left, map);
		searchBST(cur->right, map);
		return;
	}
	bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
	
		return a.second > b.second;
	}
public:
	vector<int>findMode(TreeNode* root) {
	
		unordered_map<int, int>map;//key元素，value出现频率
		vector<int>result;
		if (root == NULL)return result;
		searchBST(root, map);
		vector<pair<int, int>>vec(map.begin(), map.end());
		sort(vec.begin(), vec.end(), cmp);//给频率排序
		result.push_back(vec])
	}
};