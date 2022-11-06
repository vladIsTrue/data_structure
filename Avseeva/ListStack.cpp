#include "ListStack.h"

bool ListStack::isEmpty()
{
	return top == nullptr;
}
void ListStack::push(const datatype value)
{
	Node* p = new Node;
	p->data = value;
	p->next = top;
	top = p;

}
void ListStack::pop()
{
	if (!isEmpty())
	{
		Node* p = top;
		top = p->next;
		delete p;
		p = nullptr;
	}
}
void ListStack::clear()
{
	while (!isEmpty())
	{
		pop();
	}
}
datatype ListStack::peak()
{
	return top->data;
}

//
bool ListStack::isCorrect(const string& str) {
	ListStack stack;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			stack.push(str[i]);
		else
		{
			if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			{
				if (stack.isEmpty()
					|| (stack.peak() == '(' ^ str[i] == ')') //f^f=f
					|| (stack.peak() == '[' ^ str[i] == ']') //f^f=f
					|| (stack.peak() == '{' ^ str[i] == '}'))//t^t=f
					return false;
			}
			else stack.pop();
		}
	}
	return stack.isEmpty();
}

//преобразование инфиксного выражения в постфиксное a+b->ab+ (префиксная +ab) 

