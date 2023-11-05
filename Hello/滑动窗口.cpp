#include<iostream>
#include<vector>
#include<climits> // ���� INT_MAX

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT32_MAX;
		int sum = 0;//����������ֵ֮��
		int i = 0;//����������ʵλ��
		int subLength = 0;//�������ڵĳ���
		for (int j = 0; j < nums.size(); j++)
		{
			sum += nums[j];
			while (sum >= s)
			{
				subLength = j - i + 1;//ȥ�����еĳ���
				result = result < subLength ? result : subLength;
				sum -= nums[i++];//���ϱ��i
			}
		}
		return result == INT32_MAX ? 0 : result;
	}
};

int main() {
	// �� main ��������Ӵ��������� minSubArrayLen ����
	Solution solution;
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	int s = 7;
	int result = solution.minSubArrayLen(s, nums);

	cout << "Minimum subarray length: " << result << endl;

	return 0;
}