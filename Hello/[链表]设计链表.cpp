#include <iostream>
//#include <sstream>
#include <string>
#include <vector>
//#include <stdio.h>
#include <algorithm>
//#include <limits.h>   //INT_MIN �� INT_MAX��ͷ�ļ�
using namespace std;

class MyLinkedList {
public:
	//��������ڵ�ṹ��
	struct LinkedNode {
		int val;
		LinkedNode* next;
		LinkedNode(int val):val(val), next(nullptr) {}
	};

	//��ʼ������
	MyLinkedList() {
	
		_dummyHead = new LinkedNode(0);//�����ͷ�ڵ㣬��һ������ͷ�ڵ㣬����������ͷ�ڵ�
		_size = 0;
	}

	//��ȡ����index��������ֵ�����index�ǷǷ���ֱֵ�ӷ���-1��index�Ǵ�0��ʼ����0���ڵ����ͷ�ڵ�
	int get(int index) {
	
		if (index < 0 || index > (_size - 1))
		{
			return -1;
		}
		LinkedNode* cur = _dummyHead->next;
		while (index--)
		{
			cur = cur->next;
		}
		return cur->val;
	}

	//��������ǰ�����һ���ڵ㣬������ɺ��²���Ľڵ�������µ�ͷ�ڵ�
	void addAtHead(int val) {
	
		LinkedNode* newNode = new LinkedNode(val);
		newNode->next = _dummyHead->next;
		_dummyHead->next = newNode;
		_size++;
	}

	//��������������һ���ڵ�
	void addAtTail(int val) {
	
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = newNode;
		_size++;
	}

	//�ڵ�index���ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
	//���index��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β�ڵ�
	//���index��������ĳ��ȣ��򷵻ؿ�
	//���indexС��0������ͷ������ڵ�

	void addAtIndex(int val,int index) {
	
		if (index > _size) return;
		if (index < 0) index = 0;
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (index--)
		{
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		_size++;
	}
	//ɾ����index���ڵ㣬���index���ڵ�������ĳ���ֱ��return��ע��index�Ǵ�0��ʼ��
	void deleteAtIndex(int index) {
	
		if (index > _size || index < 0) {
		
			return;
		}
		LinkedNode* cur = _dummyHead;
		while (index--)
		{
			cur = cur->next;
		}
		LinkedNode* tmp = cur->next;
		cur->next = cur->next->next;
		//delete����ָʾ�ͷ���tmpָ��ԭ����ָ���ǲ����ڴ棬
		//��delete���ָ��tmp��ֵ����ַ�����Ǿ���NULL���������ֵ��Ҳ���Ǳ�delete��
		//������ټ���һ��tmp=nullptr,tmp���Ϊ��ָ��Ұָ��
		//���֮��ĳ���С��ʹ����tmp����ָ������Ԥ����ڴ�ռ�
		delete tmp;

		tmp = nullptr;
		_size--;
	}

	//��ӡ����
	void printfLinkedList() {
	
		LinkedNode* cur = _dummyHead;
		while (cur->next != nullptr)
		{
			cout << cur->next->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
private:
	int _size;
	LinkedNode* _dummyHead;
};

int main() {
	MyLinkedList list;

	// ������ͷ����ӽڵ�
	list.addAtHead(1);
	list.addAtHead(2);
	list.addAtHead(3);

	cout << "Linked List after adding at head: ";
	list.printfLinkedList(); // ��ӡ����

	// ������β����ӽڵ�
	list.addAtTail(4);
	list.addAtTail(5);

	cout << "Linked List after adding at tail: ";
	list.printfLinkedList(); // ��ӡ����

	// ��ָ��λ�ò���ڵ�
	list.addAtIndex(6, 2);

	cout << "Linked List after adding at index 2: ";
	list.printfLinkedList(); // ��ӡ����

	// ɾ��ָ��λ�õĽڵ�
	list.deleteAtIndex(1);

	cout << "Linked List after deleting at index 1: ";
	list.printfLinkedList(); // ��ӡ����

	return 0;
}
