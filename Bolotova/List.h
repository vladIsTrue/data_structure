#pragma once

struct Node
{
	int data;
	Node* next;
};

class List
{
	Node* head;

public:
	//Node* head;
	List()
	{
		head = 0;
	}
	~List()
	{
		deleteAll();
	}

	bool isEmpty();

	void addToHead(int elem);
	void addAfterTail(int elem);
	void addAfterCur(int cur, int elem);

	void deleteHead();
	void deleteTail();
	void deleteAll();
	void deleteAfterCur(int cur);

	void printList();

	Node* search(int elem);
};