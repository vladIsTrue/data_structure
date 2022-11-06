#include "Stack.h"

bool Stack::isEmpty()
{
	return top == 0;
}
void Stack::push(const int value)
{
	Node* p = new Node;
	p->data = value;
	p->next = top;
	top = p;

}
void Stack::pop()
{
	if (!isEmpty())
	{
		Node* p = top;
		top = p->next;
		delete p;
		p = 0;
	}
}
void Stack::clear()
{
	while (!isEmpty())
	{
		pop();
	}
}
int Stack::peak()
{
	return top->data;
}