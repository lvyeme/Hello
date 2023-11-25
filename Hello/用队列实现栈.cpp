#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class MyStack {

public:
	queue<int> que;
	MyStack() {

	}
	void push(int x) {
		que.push(x);
	}

	int pop() {
		int size = que.size();
		//--��ȥ���һ��Ԫ��
		while (size--)//������ͷ��Ԫ�أ����һ��Ԫ�س��⣩ȫ��������ӵ�����β��
		{
			que.push(que.front());
			que.pop();
		}
		int result = que.front();
		que.pop();
		return result;
	}

	int top() {
		return que.back();
	}

	bool empty() {
		return que.empty();
	}
};

int main() {
	MyStack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	cout << stack.pop() << endl; // Output: 3
	cout << stack.top() << endl; // Output: 2

	return 0;
}