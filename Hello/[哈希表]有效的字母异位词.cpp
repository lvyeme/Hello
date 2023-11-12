#include <iostream>

using namespace std;

class Solution {
public:

	bool isAnagram(string s,string t) {
	
		int record[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			record[s[i] - 'a']++;//记录第一个字母数组中字母的个数
		}
		for (int i = 0; i < t.size(); i++) {
			record[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (record[i] != 0) {
				// record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
				return false;
			}
		}
		//record数组所有元素都为零，说明字符串s和t是字母异位词
		return true;
	}

	/*bool isAnagram(string s, string t) {
		int count[26] = { 0 };
		for (char c : s) count[c - 'a']++;
		for (char c : t) count[c - 'a']--;
		for (int i = 0; i < 26; i++) if (count[i]) return false;
		return true;
	}*/
};

int main() {
	Solution slou;
	string s = "qwer";
	string t = "qwer";

	bool result = slou.isAnagram(s, t);
	cout << result << endl;

	return 0;
}

