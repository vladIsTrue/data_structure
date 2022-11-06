#pragma once

struct Node 
{
	int data;
	Node* next;
};

typedef Node* TList;

void initList(TList& head, int elem);
bool isEmpty(TList head);
void addAfterNode(TList& pNode, int elem);
void deleteAfterNode(TList pNode, TList& head);
void printList(TList head);
void clear(TList& head);

//Задача Флавия
void kill(TList& head, int n);
TList fillList(int n);

//дз на 12.10
//1)
void deleteFirstNegative(TList& head);
//2)
bool atLeastOne(TList head);
//3)
void twiceE(TList& head, int E);
//4)
int countSameNeighbours(TList head);
//5)
void delWhoHaveSameNeighbours(TList& head);