#include "ListQueue.h"

ListQueue::ListQueue()
{
	head = tail = nullptr;
}
ListQueue::~ListQueue()
{
	clear();
}

void ListQueue::clear()
{
	while (!is_empty())
	{
		deque();
	}
}
bool ListQueue::is_empty()
{
	return head == nullptr;
}

void ListQueue::enque(const int value)
{
	Node* p = new Node;
	p->data = value;
	p->next = nullptr;

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
void ListQueue::deque()
{
	if (head != nullptr)
	{
		Node* p = head;
		head = p->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
	}

}

int ListQueue::peek()
{
	return head->data; // Опасно, если head == nullptr
}
