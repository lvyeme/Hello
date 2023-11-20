#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void reverse(string& s, int start, int end) {//��ת������д��������ұ�
	
		for (int i = start, j = end; i < j; i++)
		{
			swap(s[i], s[j]);
		}
	}

	void removeExtraSpaces(string& s) {//ȥ�����пո������ڵ���֮����ӿո񣬿���ָ��.
		int slow = 0;
		for (int i = 0; i < s.size(); i++)
		{			
			if (s[i] != ' ')//�����ո�ʹ�����ɾ�����Կո�
			{
				if (slow != 0) s[slow++] = ' ';//�ֶ����ƿո񣬸�����֮����ӿո�.
				                               //slow��=0˵�����ǵ�һ�����ʣ���Ҫ�ڵ���ǰ��ӿո�
				while (i < s.size() && s[i] != ' ')//���ϸõ��ʣ������ո�˵�����ʽ���
				{
					s[slow++] = s[i++];
				}
			}
		}
		s.resize(slow);//slow�Ĵ�С��Ϊȥ������ո��Ĵ�С
	}

	string reverseWord(string s) {
	
		removeExtraSpaces(s);//ȥ������ո񣬱�֤����֮��ֻ��һ���ո����ַ�����βû�ո�
		reverse(s, 0, s.size() - 1);
		int start = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (i == s.size() || s[i] == ' ') {//����ո���ߴ�β��˵��һ�����ʽ��������з�ת
			
				reverse(s, start, i - 1);//��ת��������ұ�[]�ķ�ת��
				start = i + 1;//������һ�����ʵĿ�ʼ�±�start
			}
		}
		return s;
	}
};