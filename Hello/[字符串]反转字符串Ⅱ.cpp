#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
	
		//1.每隔2k个字母的前k个字符进行反转
		//2.剩余字符小于2k但大于或等于k个，则反转k个字符
		for (int i = 0; i < s.size(); i += (2 * k))
		{
			if (i + k < s.size()) {
			
				reverse(s.begin() + i, s.begin() + i + k);
			}
			else
			{
				//3.剩余字符少于k个，则剩余字符全部反转
				reverse(s.begin() + i, s.end());
			}
		}
		return s;
	}
};