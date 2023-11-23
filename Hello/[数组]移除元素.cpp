#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
	
		int slowIndex = 0;
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
		{
			if (val != nums[fastIndex]) {
			
				nums[slowIndex++] = nums[fastIndex];
			}
		}
		//nums.resize(slowIndex); // 将 nums 数组大小调整为 slowIndex，即删除了后面的元素
		return slowIndex;
	}
};

int main() {
    Solution solu;
    vector<int> nums = { 1, 6, 3, 4, 2, 5 };
    int val = 2;
    int newSize = solu.removeElement(nums, val);

    cout << "旧数组元素：";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "新数组元素：";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
