#include <iostream>

using namespace std;

//��������
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
		ListNode* fast = dummyHead;//��ʼ��ָ����ʼλ��
		ListNode* slow = dummyHead;//��ʼ��ָ����ʼλ��
		n++;
		// �ÿ�ָ������ n ��
		while (n-- && fast != NULL)
		{
			fast = fast->next;
		}
		//fast = fast->next;//fast����ǰ��һ�� ��Ϊ��Ҫ��slowָ��ɾ���ڵ����һ���ڵ�

		while (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		// ɾ�������� n ���ڵ�
		//slow->next = slow->next->next;

		ListNode* temp = slow->next;//c++�ͷ��ڴ���߼�
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
//		fast = fast->next; // fast����ǰ��һ������Ϊ��Ҫ��slowָ��ɾ���ڵ����һ���ڵ�
//		while (fast != NULL) {
//			fast = fast->next;
//			slow = slow->next;
//		}
//		slow->next = slow->next->next;
//
//		 ListNode *tmp = slow->next;  //C++�ͷ��ڴ���߼�
//		 slow->next = tmp->next;
//		 delete tmp;
//
//		return dummyHead->next;
//	}
//};

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
	head->next->next->next = new ListNode(4);

	cout << "Original List: ";
	printList(head);

	// ɾ�������� n ���ڵ�
	int n = 2; // ����Ҫɾ�������ڶ����ڵ�
	head = solution.removeNthFromEnd(head, n);

	cout << "Updated List: ";
	printList(head);

	return 0;
}