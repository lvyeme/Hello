#include <iostream>

using namespace std;

//定义链表
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
class Solution {
public:

	ListNode* swapPairs(ListNode* head) {
	
		ListNode* dummyHead = new ListNode(0);//设置一个虚拟头节点
		dummyHead->next = head;//将虚拟头节点指向head，这样方便做后续删除操作
		ListNode* cur = dummyHead;
		while (cur->next != nullptr && cur->next->next != nullptr)
		{
			ListNode* temp = cur->next;//记录临时节点 保存节点一
			ListNode* temp1 = cur->next->next->next;  //保存节点三

			cur->next = cur->next->next;
			cur->next->next = temp;
			cur->next->next->next = temp1;

			cur = cur->next->next;
		}
		return dummyHead->next;
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
	head->next->next->next = new ListNode(4);

	cout << "Original List: ";
	printList(head);

	// 交换链表
	head = solution.swapPairs(head);

	cout << "swapPairs List: ";
	printList(head);

	return 0;
}