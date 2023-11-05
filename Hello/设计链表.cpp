#include <iostream>
//#include <sstream>
#include <string>
#include <vector>
//#include <stdio.h>
#include <algorithm>
//#include <limits.h>   //INT_MIN 和 INT_MAX的头文件
using namespace std;

class MyLinkedList {
public:
	//定义链表节点结构体
	struct LinkedNode {
		int val;
		LinkedNode* next;
		LinkedNode(int val):val(val), next(nullptr) {}
	};

	//初始化链表
	MyLinkedList() {
	
		_dummyHead = new LinkedNode(0);//定义的头节点，是一个虚拟头节点，不是真正的头节点
		_size = 0;
	}

	//获取到第index个几点数值，如果index是非法数值直接返回-1，index是从0开始，第0个节点就是头节点
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

	//在链表最前面插入一个节点，插入完成后，新插入的节点链表的新的头节点
	void addAtHead(int val) {
	
		LinkedNode* newNode = new LinkedNode(val);
		newNode->next = _dummyHead->next;
		_dummyHead->next = newNode;
		_size++;
	}

	//在链表最后面添加一个节点
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

	//在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
	//如果index等于链表的长度，则说明是新插入的节点为链表的尾节点
	//如果index大于链表的长度，则返回空
	//如果index小于0，则在头部插入节点

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
	//删除第index个节点，如果index大于等于链表的长度直接return，注意index是从0开始的
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
		//delete命令指示释放了tmp指针原本所指的那部分内存，
		//被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
		//如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
		//如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
		delete tmp;

		tmp = nullptr;
		_size--;
	}

	//打印链表
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

	// 在链表头部添加节点
	list.addAtHead(1);
	list.addAtHead(2);
	list.addAtHead(3);

	cout << "Linked List after adding at head: ";
	list.printfLinkedList(); // 打印链表

	// 在链表尾部添加节点
	list.addAtTail(4);
	list.addAtTail(5);

	cout << "Linked List after adding at tail: ";
	list.printfLinkedList(); // 打印链表

	// 在指定位置插入节点
	list.addAtIndex(6, 2);

	cout << "Linked List after adding at index 2: ";
	list.printfLinkedList(); // 打印链表

	// 删除指定位置的节点
	list.deleteAtIndex(1);

	cout << "Linked List after deleting at index 1: ";
	list.printfLinkedList(); // 打印链表

	return 0;
}
