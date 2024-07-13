#include <iostream>
#include <vector>
#include <climits> // for INT32_MAX


using namespace std;

class Solution {
public :
	int minSubArrayLen(int s, vector<int>nums) {
	
		int result = INT32_MAX;
		int i = 0;
		int sum = 0;
		int subLenght = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			sum += nums[j];
			while (sum >= s)
			{
				subLenght = (j-i+1);
				result = result < subLenght ? result : subLenght;
				sum -= nums[i++];
			}
		}
		return result == INT32_MAX ? 0 : result;
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	int s = 3;
	int result = solution.minSubArrayLen(s, nums);
	cout << "The minimum length of a subarray that sums to at least " << s << " is " << result << endl;

	return 0;
}