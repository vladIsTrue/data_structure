#include "circularList.h"
#include <iostream>
using namespace std;

void initList(TList& head, int elem)
{
	head = new Node;
	head->data = elem;
	head->next = head;
}
bool isEmpty(TList head) {
	return head->next == head;
}
void addAfterNode(TList& pNode, int elem)
{
	TList p = new Node;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
}
void deleteAfterNode(TList pNode, TList& head)
{
	TList p = pNode->next;
	if (p == head)
		head = p->next;
	pNode->next = p->next;
	delete p;
	p = nullptr;
}
void printList(TList head)
{	
	TList p = head;
	while (p->next != head) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << p->data << endl;
}
void clear(TList& head)
{
	while (!isEmpty(head))
		deleteAfterNode(head, head);
	delete head;
	head = nullptr;
}

//задача Флавия
void kill(TList& head, int n)
{
	TList p = head;
	while (!isEmpty(head))
	{
		for (int i = 0; i < n; i++)
		{
			p = p->next;
		}
		deleteAfterNode(p, head);
	}
}
TList fillList(int n)
{
	TList list;
	initList(list, 1);
	TList p = list;

	for (int i = 2; i <= n; i++)
	{
		addAfterNode(p, i);
		p = p->next;
	}
	return list;
}

//дз на 12.10
void deleteFirstNegative(TList& head) {
	TList p = head;
	if (p->data < 0) {
		while (p->next != head) p = p->next;
		deleteAfterNode(p, head);
	}
	else {
		while (p->next->data >= 0 && p->next != head)	p = p->next;
			
		if (p->next->data < 0) deleteAfterNode(p, head);
	}
}
bool atLeastOne(TList head) {
	bool ans = false;
	TList p = head;
	while (p->next != head && p->data != p->next->data) p = p->next;
	if (p->data == p->next->data) ans = true;

	return ans;
}
void twiceE(TList& head, int E) {
	TList p = head;
	while (p->next != head) {
		if (p->data == E) {
			addAfterNode(p, E);
			p = p->next;
		}
		p = p->next;
	}

	if (p->data == E) addAfterNode(p, E);
}
int countSameNeighbours(TList head) {
	TList p = head;
	int k = 0;
	while (p->next != head) {
		if (p->data == p->next->next->data) k++;
		p = p->next;
	}
	if (p->data == p->next->next->data) k++;

	return k;
}
void delWhoHaveSameNeighbours(TList& head) {
	TList p = head;
	if (p->next != head && p->next->next != head) {
		int count = 1;
		p = head;
		while (p->next != head) {
			count++;
			p = p->next;
		}

		bool* flag = new bool[count];
		p = head;
		for (int i = 1; i < count; i++) {
			if (p->data == p->next->next->data) flag[i] = true; else flag[i] = false;
			p = p->next;
		}
		if (p->data == p->next->next->data) flag[0] = true; else flag[0] = false;

		p = head;
		for (int i = 1; i < count; i++){
			if (flag[i] == true) deleteAfterNode(p, head); else p = p->next;
		}
		if (flag[0] == true) deleteAfterNode(p, head);

		delete[] flag;
	}
	else cout << "Less than three elements!" << endl;
}