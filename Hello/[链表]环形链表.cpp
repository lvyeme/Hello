#include <iostream>

using namespace std;

//定义链表
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
	
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			//快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
			if (slow == fast)
			{
				ListNode* index1 = fast;//相遇点
				ListNode* index2 = head;//头节点
				while (index1 != index2)
				{
					index1 = index1->next;
					index2 = index2->next;
				}
				return index1;//返回环的入口
			}
		}
		return NULL;
	}
};

int main() {
	// 创建一个带环的链表
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = head->next; // 创建一个环，指向第二个节点

	Solution solution;

	// 调用 detectCycle 方法查找环的入口点
	ListNode* entry = solution.detectCycle(head);

	if (entry != nullptr) {
		cout << "Cycle detected at node with value: " << entry->val << endl;
	}
	else {
		cout << "No cycle detected." << endl;
	}

	return 0;
}

