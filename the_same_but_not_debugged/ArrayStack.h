#pragma once

// при реализации стека в виде массива выигрывает в памяти

class ArrayStack
{
private:
	int* stack;
	int size;
	int top;

public:

	ArrayStack(int size)
	{
		stack = new int[size];
		this->size = size;
		top = -1;
	}


	bool is_empty();
	void push(const int value);
	void pop();
	int peek();
	void clear();





	~ArrayStack()
	{
		delete[] stack;
		stack = nullptr;
		top = -1;
		size = 0;
	}
};

