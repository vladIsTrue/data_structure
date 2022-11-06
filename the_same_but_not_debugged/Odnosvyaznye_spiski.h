#pragma once

struct Node {
	int data;
	Node* next;
};

typedef Node* TList;

void initList(TList& head);
bool isEmpty(TList head);

void addToHead(TList& head, int elem);
void addAfterTail(TList& head, int elem);
void addAfterCur(TList& head, int cur, int elem);

void delHead(TList& head);
void delTail(TList& head);
void delAll(TList& head);
void delAfterCur(TList& head, int cur);
void delAllSame(TList& head, int cur);

void printList(TList head);

TList search(TList head, int elem);

void addAfterNode(TList& pNode, int elem);