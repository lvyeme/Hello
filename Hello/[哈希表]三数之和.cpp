#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
	
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		//找出a + b +c =0;
		//a = nums[i],b = nums[j],c = -(a + b)
		for (int i = 0; i < nums.size(); i++)
		{
			//排序后如果第一个数字大于零则直接返回
			if (nums[i] > 0) {
				return result;
			}
			//错误去重a方法，将会漏掉-1，--1，-2，这种情况

			//正确去重
			if (i > 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (right > left)
			{
				if (nums[i] + nums[left] + nums[right] > 0) right--;
				else if (nums[i] + nums[left] + nums[right] < 0) left++;
				else
				{
					result.push_back(vector<int>{nums[i],nums[left], nums[right]});
					//去重逻辑应该放在找到一个三元组之后，对b 和 c去重
					while (right > left && nums[right] == nums[right - 1]) right--;
					while (right > left && nums[left] == nums[left + 1]) left++;
					
					//找到答案时，双指针同时收缩
					right--;
					left++;
				}
			}
		}
		return result;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result = solution.threeSum(nums);
	for (auto v : result) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}