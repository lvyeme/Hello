#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
	stack <int> stIn;
	stack <int> stOut;

	MyQueue() {
	
	}

	void push(int x) {
		stIn.push(x);
	}

	int pop() {
		//ֻ�е�stOutΪ��ʱ���ٴ�stIn�ﵼ������
		if (stOut.empty())
		{
			//��stIn��������ֱ��stinΪ��
			while (!stIn.empty())
			{
				stOut.push(stIn.top());
				stIn.pop();
			}
		}
		int result = stOut.top();
		stOut.pop();
		return result;
	}

	int peek() {
	
		int res = this->pop();//ֱ��ʹ�����е�pop����
		stOut.push(res);//��Ϊpop����������Ԫ��res����������ӽ�ȥ
		return res;
	}

	bool empty() {
	
		return stIn.empty() && stOut.empty();
	}
};

int main() {

	MyQueue queue;

	//Test case 1
	queue.push(1);
	queue.push(2);
	cout << "��Ԫ��" << queue.peek() << endl;
	cout << "������Ԫ��" << queue.pop() << endl;
	cout << "�����ǿյ���" << (queue.empty() ? "yes" : "no" ) ;

	cout << "\n---------------------------------" << endl;

	//Test case 2
	queue.push(3);
	queue.push(4);
	cout << "������Ԫ��" << queue.pop() << endl;
	cout << "�����ǿյ���" << (queue.empty() ? "yes" : "no");

	cout << "\n---------------------------------" << endl;

	// Test case 3
	cout << "Popped element: " << queue.pop() << endl; // Output: 3
	cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Output: No

	return 0;
}
