#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int len = s.size();//��ȡ����

	reverse(s.begin(), s.end());//���巭ת
	reverse(s.begin(), s.begin()+n);//�ȷ�תǰһ�Σ�����n
	reverse(s.begin() + n, s.end());//�ٷ�ת��һ��
	cout << s << endl;
}