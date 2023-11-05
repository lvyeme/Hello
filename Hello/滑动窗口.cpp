#include<iostream>
#include<vector>
#include<climits> // 用于 INT_MAX

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;
		int sum = 0;//滑动窗口数值之和
		int i = 0;//滑动窗口其实位置
		int subLength = 0;//滑动窗口的长度
		for (int j = 0; j < nums.size(); j++)
		{
			sum += nums[j];
			while (sum >= s)
			{
				subLength = j - i + 1;//去子序列的长度
				result = result < subLength ? result : subLength;
				sum -= nums[i++];//不断变更i
			}
		}
		return result == INT32_MAX ? 0 : result;
	}
};

int main() {
	// 在 main 函数中添加代码来测试 minSubArrayLen 方法
	Solution solution;
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	int s = 7;
	int result = solution.minSubArrayLen(s, nums);

	cout << "Minimum subarray length: " << result << endl;

	return 0;
}