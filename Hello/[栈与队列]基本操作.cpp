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
		//只有当stOut为空时，再从stIn里导出数据
		if (stOut.empty())
		{
			//从stIn导入数据直到stin为空
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
	
		int res = this->pop();//直接使用已有的pop函数
		stOut.push(res);//因为pop函数弹出了元素res，所以再添加进去
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
	cout << "首元素" << queue.peek() << endl;
	cout << "弹出的元素" << queue.pop() << endl;
	cout << "队列是空的吗？" << (queue.empty() ? "yes" : "no" ) ;

	cout << "\n---------------------------------" << endl;

	//Test case 2
	queue.push(3);
	queue.push(4);
	cout << "弹出的元素" << queue.pop() << endl;
	cout << "队列是空的吗？" << (queue.empty() ? "yes" : "no");

	cout << "\n---------------------------------" << endl;

	// Test case 3
	cout << "Popped element: " << queue.pop() << endl; // Output: 3
	cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Output: No

	return 0;
}
