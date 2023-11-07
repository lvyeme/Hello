#include <iostream>

using namespace std;

//��������
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
class Solution {
public:

	ListNode* swapPairs(ListNode* head) {
	
		ListNode* dummyHead = new ListNode(0);//����һ������ͷ�ڵ�
		dummyHead->next = head;//������ͷ�ڵ�ָ��head����������������ɾ������
		ListNode* cur = dummyHead;
		while (cur->next != nullptr && cur->next->next != nullptr)
		{
			ListNode* temp = cur->next;//��¼��ʱ�ڵ� ����ڵ�һ
			ListNode* temp1 = cur->next->next->next;  //����ڵ���

			cur->next = cur->next->next;
			cur->next->next = temp;
			cur->next->next->next = temp1;

			cur = cur->next->next;
		}
		return dummyHead->next;
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
	head->next->next->next = new ListNode(4);

	cout << "Original List: ";
	printList(head);

	// ��������
	head = solution.swapPairs(head);

	cout << "swapPairs List: ";
	printList(head);

	return 0;
}