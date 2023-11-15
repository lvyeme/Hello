#include <iostream>

using namespace std;

// ����ڵ�ṹ
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

		ListNode* temp;//����cur����һ���ڵ�
		ListNode* cur = head;
		ListNode* pre = NULL;
		while (cur) {
		
			temp = cur->next; //����һ�£�cur��һ���ڵ��λ��
			cur->next = pre;//��ת����
			//����pre ��curָ��
			pre = cur;
			cur = temp;
		}
		return pre;

	}
};

// �������������ڴ�ӡ����
void printList(ListNode* head) {
	while (head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "nullptr" << endl;
}

int main() {

	// �� main ��������Ӳ��Դ���
	Solution solution;

	// ����һ���򵥵�����������
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);

	cout << "Original List: ";
	printList(head);

	// ��ת����
	head = solution.reverseList(head);

	cout << "Reversed List: ";
	printList(head);

	return 0;
}

