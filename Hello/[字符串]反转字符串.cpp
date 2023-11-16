#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
			swap(s[i], s[j]);
		}
	}
	/*char reverseString(vector<char>& str) {
	
		int i = 0 , int j = str.size()-1;
		while (i < str.size() / 2, i++,j--)
		{
			swap(str[i], str[j]);
		}
	}*/
};

int main() {

	Solution solu;
	vector<char> str = { 'h','e', 'l', 'l', 'o' };
	char result = solu.reverseString(str);
	//cout << "反转前的字符串为" << str << endl;
	cout <<"反转后的字符串为" << result << endl;

	return 0;
}