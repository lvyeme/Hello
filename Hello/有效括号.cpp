#include <iostream>
#include <stack>

using namespace std;

stack<char> st;

class Solution {
public:
	bool isValid(string s) {
	
		if (s.size() % 2 != 0)
		{
			return false;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') st.push(')');
			else if (s[i] == '{') st.push('}');
			else if (s[i] == '[') st.push(']');
			else if (st.empty() || st.top() != s[i])
				return false;
			else st.pop();
		}
		return st.empty();
	}

};

int main() {
	Solution solution;

	// ²âÊÔ×Ö·û´®
	string input1 = "()";
	string input2 = "()[]{}";
	string input3 = "(]";
	string input4 = "([)]";
	string input5 = "{[]}";

	// ²âÊÔ²¢Êä³ö½á¹û
	cout << "Input: " << input1 << " -> Valid: " << solution.isValid(input1) << endl;
	cout << "Input: " << input2 << " -> Valid: " << solution.isValid(input2) << endl;
	cout << "Input: " << input3 << " -> Valid: " << solution.isValid(input3) << endl;
	cout << "Input: " << input4 << " -> Valid: " << solution.isValid(input4) << endl;
	cout << "Input: " << input5 << " -> Valid: " << solution.isValid(input5) << endl;

	return 0;
}


