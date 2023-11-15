#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
#include<algorithm>

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
	
		int K = A.size() - 1;
		vector<int> result(A.size(), 0);
		for (int i = 0, j = A.size() - 1; i <= j;)
		{
			if (A[i] * A[i] < A[j] * A[j])
			{
				result[K--] = A[j] * A[j];
				j--;
			}
			else
			{
				result[K--] = A[i] * A[i];
				i++;
			}
		}
		return result;
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
