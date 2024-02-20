#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int len = s.size();//获取长度

	reverse(s.begin(), s.end());//整体翻转
	reverse(s.begin(), s.begin()+n);//先反转前一段，长度n
	reverse(s.begin() + n, s.end());//再翻转后一段
	cout << s << endl;
}