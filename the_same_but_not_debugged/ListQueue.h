#pragma once


class ListQueue {
	struct Node
	{
		int data;
		Node* next;
	};

	Node* head; 
	Node* tail;

public:
	ListQueue();
	~ListQueue();
	void clear();
	bool is_empty();
	void enque(const int value); // Добавление
	void deque(); // Удаление
	int peek();
};

