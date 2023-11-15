#include <iostream>

using namespace std;

//��������
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
			//����ָ����������ʱ��head �� �����㣬ͬʱ����ֱ������
			if (slow == fast)
			{
				ListNode* index1 = fast;//������
				ListNode* index2 = head;//ͷ�ڵ�
				while (index1 != index2)
				{
					index1 = index1->next;
					index2 = index2->next;
				}
				return index1;//���ػ������
			}
		}
		return NULL;
	}
};

int main() {
	// ����һ������������
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = head->next; // ����һ������ָ��ڶ����ڵ�

	Solution solution;

	// ���� detectCycle �������һ�����ڵ�
	ListNode* entry = solution.detectCycle(head);

	if (entry != nullptr) {
		cout << "Cycle detected at node with value: " << entry->val << endl;
	}
	else {
		cout << "No cycle detected." << endl;
	}

	return 0;
}

