#pragma once


class Queue 
{
	struct Node
	{
		int data;
		Node* next;
	};

	Node* head; 
	Node* tail;

public:
	Queue();
	~Queue();
	void clear();
	bool is_empty();
	void enque(const int value);
	void deque();
	int peek();
};

