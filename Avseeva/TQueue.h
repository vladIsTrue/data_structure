#pragma once

#include "Tree.h"

typedef TTree datatype;

class TQueue
{
	struct Node
	{
		datatype data;
		Node* next;
	};
	Node* head, *tail;
public:
	TQueue();
	~TQueue();
	void clear();
	bool isEmpty();
	void enque(datatype elem);
	void deque(); // удаление из головы
	datatype peek(); // работает тольок для непустой очереди
};

// очередь релаизовали через циклический массив

//class TQueue
//{
//	datatype* que;
//	int size;
//	int tail, head;
//public:
//	TQueue(int n);
//	~TQueue();
//	void clear();
//	bool isEmpty();
//	void enque(datatype elem);
//	void deque(); // удаление из головы
//	datatype peek(); // работает тольок для непустой очереди
//};