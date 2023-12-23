#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

//class Solution {
//public:
//	int evalRPN(vector<string>& s) {
//	
//		stack<int>st;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/") {
//			
//				int num1 = st.top();
//				st.pop();
//				int num2 = st.top();
//				st.pop();
//				if (s[i] == "+") st.push(num2 + num1);
//				if (s[i] == "-") st.push(num2 - num1);
//				if (s[i] == "*") st.push(num2 * num1);
//				//if (s[i] == "/") st.push(num2 / num1);
//				else if (s[i] == "/") {
//					if (num1 == 0) {
//						// Handle division by zero error
//						cout << "Error: Division by zero\n";
//						return 0; // Or handle it according to your requirement
//					}
//					st.push(num2 / num1);
//				}
//				else
//				{
//					st.push(stoi(s[i]));
//				}
//			}
//		}
//		int result = st.top();
//		st.pop(); // 把栈⾥最后⼀个元素弹出（其实不弹出也没事）
//		return result;
//
//	}
//};
class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        for (const string& token : s) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                if (token == "+") st.push(num2 + num1);
                else if (token == "-") st.push(num2 - num1);
                else if (token == "*") st.push(num2 * num1);
                else if (token == "/") {
                    if (num1 == 0) {
                        // Handle division by zero error
                        cout << "Error: Division by zero\n";
                        return 0; // Or handle it according to your requirement
                    }
                    st.push(num2 / num1);
                }
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

int main() {
	Solution solu;

	// 创建一个包含逆波兰表达式的字符串向量
	vector<string> tokens = { "2", "1", "+", "3", "*" };

	// 计算逆波兰表达式的值
	int result = solu.evalRPN(tokens);

	// 输出结果
	cout << "逆波兰表达式的值为: " << result << endl;

	return 0;
}


