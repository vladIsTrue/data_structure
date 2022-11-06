#include "TQueue.h"

TQueue::TQueue()
{
	head = 0;
	tail = 0;
}

TQueue::~TQueue()
{
	clear();
}

void TQueue::clear()
{
	while (!isEmpty())
		deque();
}

bool TQueue::isEmpty()
{
	return (head == 0);
}

void TQueue::enque(datatype elem)
{
	Node* p = new Node;
	p->data = elem;
	if (tail == 0)
	{
		head = p;
		tail = p;
	}
	else
	{
		tail->next = p;
		tail = tail->next;
	}
	tail->next = 0;
}

void TQueue::deque()
{
	Node* p = head;
	if (head != 0)
	{
		head = head->next;
		p->next = 0;
		delete p;
		p = 0;
	}
}

datatype TQueue::peek()
{
	return head->data;
}
//
//TQueue::TQueue(int n)
//{
//	size = n;
//	que = new datatype[n];
//	head = 0;
//	tail = -1;
//}
//
//TQueue::~TQueue()
//{
//	delete[] que;
//}
//
//bool TQueue::isEmpty()
//{
//	return (ефшд == -1);
//}
//
//void TQueue::enque(datatype elem)
//{
//	int count = tail - head + 1 + size * (head > tail && tail != -1);
//	if (count < size)
//	{
//		tail = (tail + 1) % size;
//		que[tail] = elem;
//	}
//}
//
//void TQueue::deque()
//{
//	int count = tail - head + 1 + size * (head > tail && tail != -1);
//	if (cout > 0)
//		head = (head + 1) % size;
//}
//
//datatype TQueue::peek() // наверное так
//{
//	return que[head];
//}