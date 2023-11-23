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
		//nums.resize(slowIndex); // �� nums �����С����Ϊ slowIndex����ɾ���˺����Ԫ��
		return slowIndex;
	}
};

int main() {
    Solution solu;
    vector<int> nums = { 1, 6, 3, 4, 2, 5 };
    int val = 2;
    int newSize = solu.removeElement(nums, val);

    cout << "������Ԫ�أ�";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "������Ԫ�أ�";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
