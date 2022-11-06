#pragma once
#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

typedef TTree datatype;

struct Node
{
	datatype data;
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
	void push(const datatype value);
	void pop();
	void clear();
	datatype peak();
	bool isCorrect(const string& str);
};