#include "myList.h"
#include <iostream>
using namespace std;

void initList(TList& head)
{
	head = nullptr;
}
bool isEmpty(TList head) {
	return head == nullptr;
}

void addToHead(TList& head, int elem)
{
	TList p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}
void addAfterTail(TList& head, int elem)
{
	TList p = head;
	while (p->next != nullptr) p = p->next;
	TList n = new Node;
	p->next = n;
	n->data = elem;
	n->next = nullptr;
}
void addAfterCur(TList& head, int cur, int elem)
{
	TList p = search(head, cur);
	TList n = new Node;
	n->data = elem;
	n->next = p->next;
	p->next = n;
}

void delHead(TList& head)
{
		TList p = head;
		head = p->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
}
void delTail(TList& head)
{
	TList p = head;
	if (p->next == nullptr) {
		delHead(head);
	}
	else {
		while (p->next->next != nullptr) {
			p = p->next;
		}
		TList n;
		n = p->next;
		delete n;
		p->next = nullptr;
		n = nullptr;
	}
}
void delAll(TList& head)
{
	while (!isEmpty(head)) {
		delHead(head);
	}
}
void delAfterCur(TList& head, int cur) {
	TList p = search(head, cur);
	
	if (p->next != nullptr) {
		TList n = p->next;
		p->next = n->next;
		n->next = nullptr;
		delete n;
		n = nullptr;
	}
}
void delAllSame(TList& head, int cur) {
	TList p = head;
	while (p != nullptr && p->data == cur) {
		head = p->next;
		p->next = nullptr;
		delete p;
		p = head;
	}

	if (p != nullptr)
		while (p->next != nullptr) {
			if (p->next->data == cur) {
				TList q = p->next;
				p->next = q->next;
				q->next = nullptr;
				delete q;
			} else p = p->next;
		}
}

void printList(TList head)
{
	if (isEmpty(head)) cout << "List is Empty!";
	else {
		TList p = head;
		while (p != nullptr) {
			cout << p->data << ' ';
			p = p->next;
		}
	}
	cout << endl;
}

TList search(TList head, int elem)
{
	TList p = head;
	while (p != nullptr && p->data != elem) {
		p = p->next;
	}

	return p;
}

void addAfterNode(TList& pNode, int elem)
{
	TList n = new Node;
	n->data = elem;
	n->next = pNode->next;
	pNode->next = n;
}