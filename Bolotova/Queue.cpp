#include "Queue.h"

Queue::Queue()
{
	head = tail = 0;
}
Queue::~Queue()
{
	clear();
}

void Queue::clear()
{
	while (!is_empty())
	{
		deque();
	}
}
bool Queue::is_empty()
{
	return head == 0;
}

void Queue::enque(const int value)
{
	Node* p = new Node;
	p->data = value;
	p->next = 0;

	if (is_empty())
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}
void Queue::deque()
{
	if (head)
	{
		Node* p = head;
		head = p->next;
		p->next = 0;
		delete p;
		p = 0;
	}

}

int Queue::peek()
{
	return head->data;
}
