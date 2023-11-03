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
		sort(A.begin(), A.end());//��������
		return A;
	}
};

int main() {
	// �� main ��������Ӵ��������� sortedSquares ����
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