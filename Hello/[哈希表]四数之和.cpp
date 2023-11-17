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
			//��֦����
			if (nums[k] > target && nums[k] >= 0 )
			{
				break;
			}
			//��nums[k]ȥ��
			if (k > 0 && nums[k] == nums[k - 1])
			{
				continue;
			}
			for (int i = k + 1; i < nums.size(); i++)
			{
				//2�������֦
				if (nums[i] + nums[k] > target && nums[i] + nums[k] >= 0)
				{
					break;
				}
				//��nums[i]ȥ��
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

						//��nums[left]��nums[right]ȥ��
						while (right > left && nums[right] == nums[right - 1]) {
							right--;
						}
						while (right > left && nums[left] == nums[left + 1]) {
							left++;
						}

						//�ҵ���ʱ��˫ָ��ͬʱ����
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

	cout << "�ĸ���֮�͵��� " << target << " �Ĳ��ظ����ϣ�" << endl;
	for (const vector<int>& res : result) {
		cout << "[";
		for (int val : res) {
			cout << val << ", ";
		}
		cout << "]" << endl;
	}

	return 0;
}
