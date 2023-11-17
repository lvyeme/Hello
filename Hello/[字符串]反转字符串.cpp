#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*vector<char> reverseString(vector<char>& s) {
		for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
			swap(s[i], s[j]);
		}
		return s;
	}*/
	vector<char> reverseString(vector<char>& str) {
	
		int i = 0 , j = str.size()-1;

		while (i < j)
		{
			swap(str[i++], str[j--]);
		}
		return str;
	}
};

int main() {
	Solution solu;
	vector<char> str = { 'h','e', 'l', 'l', 'o' };
	vector<char> result = solu.reverseString(str);

	cout << "反转后的字符串为: ";
	for (char ch : result) {
		cout << ch;
	}
	cout << endl;

	return 0;
}