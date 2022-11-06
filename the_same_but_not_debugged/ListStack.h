#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class ListStack
{
	Node* top;

public:
	ListStack()
	{
		top = nullptr;
	}
	~ListStack()
	{
		clear();
	}

	bool isEmpty();
	void push(const int value);
	void pop();
	void clear();
	int peak();
	bool isCorrect(const string& str);
};