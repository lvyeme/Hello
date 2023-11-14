#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	
		unordered_map<int, int> umap;//key:a+b的数值，value:A+b出现的次数
		for (int a : A)
		{
			for (int b : B)
			{
				umap[a + b]++;
			}
		}
		int count = 0;//统计a+b+c+d = 0 出现的次数
		for  (int c : C)
		{
			for (int d : D) {
				if (umap.find(0 - (c + d)) != umap.end())
				{
					count += umap[0 - (c + d)];
				}
			}
		}
		return count;
	}
};

int main() {
	Solution solution;
	vector<int> A = { 1, 2 };
	vector<int> B = { -2, -1 };
	vector<int> C = { -1, 2 };
	vector<int> D = { 0, 2 };

	int result = solution.fourSumCount(A, B, C, D);
	cout << "Number of tuples: " << result << endl;

	return 0;
}