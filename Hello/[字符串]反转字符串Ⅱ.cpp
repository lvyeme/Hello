#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
	
		//1.ÿ��2k����ĸ��ǰk���ַ����з�ת
		//2.ʣ���ַ�С��2k�����ڻ����k������תk���ַ�
		for (int i = 0; i < s.size(); i += (2 * k))
		{
			if (i + k < s.size()) {
			
				reverse(s.begin() + i, s.begin() + i + k);
			}
			else
			{
				//3.ʣ���ַ�����k������ʣ���ַ�ȫ����ת
				reverse(s.begin() + i, s.end());
			}
		}
		return s;
	}
};