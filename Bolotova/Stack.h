#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* next;
};

class Stack
{
	Node* top;

public:
	Stack()
	{
		top = nullptr;
	}
	~Stack()
	{
		clear();
	}

	bool isEmpty();
	void push(const int value);
	void pop();
	void clear();
	int peak();
};