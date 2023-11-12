#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& unms, int target) {
	
		std::unordered_map<int, int> map;
		for (int i = 0; i < unms.size(); i++)
		{
			//遍历当前元素，并在map中寻找是否有匹配的key
			auto iter = map.find(target - unms[i]);
			if (iter != map.end())
			{
				return { iter->second,i };
			}
			//如果没有找到匹配对，就把访问过元素和下标加入到map中
			map.insert(pair<int, int>(unms[i], i));
		}
		return {};
	}

};
int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = { 2, 7, 3, 6 };
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test Case 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 2
    //vector<int> nums2 = { 3, 2, 4 };
    //int target2 = 6;
    //vector<int> result2 = solution.twoSum(nums2, target2);
    //cout << "Test Case 2: ";
    //for (int num : result2) {
    //    cout << num << " ";
    //}
    //cout << endl;

    //// Test Case 3
    //vector<int> nums3 = { 3, 3 };
    //int target3 = 6;
    //vector<int> result3 = solution.twoSum(nums3, target3);
    //cout << "Test Case 3: ";
    //for (int num : result3) {
    //    cout << num << " ";
    //}
    //cout << endl;

    //return 0;
}
