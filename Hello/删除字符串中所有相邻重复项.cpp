#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	string removeDuplicate(string S) {
	
		string result;
		for (char s : S )
		{

			if (result.empty() || result.back() != s)
			{
				result.push_back(s);
			}
			else {
			
				result.pop_back();
			}
		}
		return result;
	}
};

int main() {
	Solution solu;

	// ��������ظ���ĸ���ַ���
	string input = "abbaca";

	// ɾ���ַ����е��ظ���ĸ
	string result = solu.removeDuplicate(input);

	// ������
	cout << "ɾ���ظ���ĸ����ַ���Ϊ: " << result << endl;

	return 0;
}
