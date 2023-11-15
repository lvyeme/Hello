#include <iostream>

using namespace std;

// 链表节点结构
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}

		ListNode* temp;//保存cur的下一个节点
		ListNode* cur = head;
		ListNode* pre = NULL;
		while (cur) {
		
			temp = cur->next; //保存一下，cur下一个节点的位置
			cur->next = pre;//翻转操作
			//更新pre 和cur指针
			pre = cur;
			cur = temp;
		}
		return pre;

	}
};

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

	cout << "Original List: ";
	printList(head);

	// 反转链表
	head = solution.reverseList(head);

	cout << "Reversed List: ";
	printList(head);

	return 0;
}

