#include <iostream>

using namespace std;

class Solution {
public:

	bool isAnagram(string s,string t) {
	
		int record[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			record[s[i] - 'a']++;//��¼��һ����ĸ��������ĸ�ĸ���
		}
		for (int i = 0; i < t.size(); i++) {
			record[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (record[i] != 0) {
				// record��������е�Ԫ�ز�Ϊ��0��˵���ַ���s��t һ����˭�����ַ�����˭�����ַ���
				return false;
			}
		}
		//record��������Ԫ�ض�Ϊ�㣬˵���ַ���s��t����ĸ��λ��
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

