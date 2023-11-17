#include <iostream>
#include <vector>
//#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> foruNumsSum(int target,vector<int>& nums) {
	
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int k = 0; k < nums.size(); k++)
		{
			//剪枝处理
			if (nums[k] > target && nums[k] >= 0 )
			{
				break;
			}
			//对nums[k]去重
			if (k > 0 && nums[k] == nums[k - 1])
			{
				continue;
			}
			for (int i = k + 1; i < nums.size(); i++)
			{
				//2级处理剪枝
				if (nums[i] + nums[k] > target && nums[i] + nums[k] >= 0)
				{
					break;
				}
				//对nums[i]去重
				if (i > k + 1 && nums[i] == nums[i - 1])
				{
					continue;
				}
				int left = i + 1;
				int right = nums.size() - 1;
				while (right > left)
				{
					if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
					else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target) left++;
					else
					{
						result.push_back(vector<int> {nums[k], nums[i], nums[left], nums[right]});

						//对nums[left]和nums[right]去重
						while (right > left && nums[right] == nums[right - 1]) {
							right--;
						}
						while (right > left && nums[left] == nums[left + 1]) {
							left++;
						}

						//找到答案时，双指针同时收缩
						left++;
						right--;
					}
				}
			}
		}
		return result;
	}
};

int main() {
	Solution solu;
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	int target = 0;

	vector<vector<int>> result = solu.foruNumsSum(target, nums);

	cout << "四个数之和等于 " << target << " 的不重复集合：" << endl;
	for (const vector<int>& res : result) {
		cout << "[";
		for (int val : res) {
			cout << val << ", ";
		}
		cout << "]" << endl;
	}

	return 0;
}
