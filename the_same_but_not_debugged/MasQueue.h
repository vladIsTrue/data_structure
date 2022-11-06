#pragma once
using namespace std;

class MasQueue {
	int* que; //datatype
	int size;
	int tail, head;
	//int count - для того что бы каждый раз не пересчитывать

public:
	MasQueue(int n);
	~MasQueue();
	void clear();
	bool is_empty();
	void enque(const int value); // Добавление
	void deque(); // Удаление
	int peek();
}