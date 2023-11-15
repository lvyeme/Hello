#include<iostream>
using namespace std;
#include<vector>
#include <math.h>
#include <algorithm>

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		for (int i = 0; i < A.size(); i++)
		{
			A[i] *= A[i];
		}
		sort(A.begin(), A.end());//快速排序
		return A;
	}
};

int main() {
	// 在 main 函数中添加代码来测试 sortedSquares 方法
	Solution solution;
	vector<int> A = { -4, -1, 0, 3, 10 };
	vector<int> result = solution.sortedSquares(A);

	cout << "Sorted Squares: ";
	for (int num : result) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}