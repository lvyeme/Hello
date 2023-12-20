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

	// 输入包含重复字母的字符串
	string input = "abbaca";

	// 删除字符串中的重复字母
	string result = solu.removeDuplicate(input);

	// 输出结果
	cout << "删除重复字母后的字符串为: " << result << endl;

	return 0;
}
