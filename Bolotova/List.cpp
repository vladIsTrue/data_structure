#include "List.h"
#include <iostream>

bool List::isEmpty()
{
	return head == 0;
}

void List::addToHead(int elem)
{
	Node * p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}

void List::addAfterTail(int elem)
{
	Node * p = head;
	while (p->next)
		p = p->next;
	Node * n = new Node;
	p->next = n;
	n->data = elem;
	n->next = 0;
}

void List::addAfterCur(int cur, int elem)
{
	Node * p = search(cur);
	Node * n = new Node;
	n->data = elem;
	n->next = p->next;
	p->next = n;
}

void List::deleteHead()
{
	Node * p = head;
	head = p->next;
	p->next = 0;
	delete p;
	p = 0;
}

void List::deleteTail()
{
	Node * p = head;
	if (p->next == 0)
	{
		deleteHead();
	}
	else {
		while (p->next->next)
		{
			p = p->next;
		}
		Node * n;
		n = p->next;
		delete n;
		p->next = 0;
		n = 0;
	}
}

void List::deleteAll()
{
	while (!isEmpty())
	{
		deleteHead();
	}
}

void List::deleteAfterCur(int cur)
{
	Node * p = search(cur);

	if (p->next)
	{
		Node * n = p->next;
		p->next = n->next;
		n->next = 0;
		delete n;
		n = 0;
	}
}

void List::printList()
{
	if (isEmpty()) 
		std::cout << "List is Empty!";
	else {
		Node * p = head;
		while (p != nullptr)
		{
			std::cout << p->data << ' ';
			p = p->next;
		}
	}
	std::cout << '\n';
}

Node* List::search(int elem)
{
	Node* p = head;
	while (p && p->data != elem)
	{
		p = p->next;
	}

	return p;
}
