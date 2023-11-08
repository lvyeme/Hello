#include <iostream>

using namespace std;

//定义链表
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head,int n) {
	
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* fast = dummyHead;//初始快指针起始位置
		ListNode* slow = dummyHead;//初始慢指针起始位置
		n++;
		// 让快指针先走 n 步
		while (n-- && fast != NULL)
		{
			fast = fast->next;
		}
		//fast = fast->next;//fast再提前走一步 因为需要让slow指向删除节点的上一个节点

		while (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		// 删除倒数第 n 个节点
		//slow->next = slow->next->next;

		ListNode* temp = slow->next;//c++释放内存的逻辑
		slow->next = temp->next;
		delete temp;

		return dummyHead->next;
	}
};

//class Solution {
//public:
//	ListNode* removeNthFromEnd(ListNode* head, int n) {
//		ListNode* dummyHead = new ListNode(0);
//		dummyHead->next = head;
//		ListNode* slow = dummyHead;
//		ListNode* fast = dummyHead;
//		while (n-- && fast != NULL) {
//			fast = fast->next;
//		}
//		fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
//		while (fast != NULL) {
//			fast = fast->next;
//			slow = slow->next;
//		}
//		slow->next = slow->next->next;
//
//		 ListNode *tmp = slow->next;  //C++释放内存的逻辑
//		 slow->next = tmp->next;
//		 delete tmp;
//
//		return dummyHead->next;
//	}
//};

// 辅助函数，用于打印链表
void printList(ListNode* head) {
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "nullptr" << endl;
}

int main() {
	// 在 main 函数中添加测试代码
	Solution solution;

	// 创建一个简单的链表来测试
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	cout << "Original List: ";
	printList(head);

	// 删除倒数第 n 个节点
	int n = 2; // 假设要删除倒数第二个节点
	head = solution.removeNthFromEnd(head, n);

	cout << "Updated List: ";
	printList(head);

	return 0;
}