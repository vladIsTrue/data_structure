#pragma once

#include <iostream> // он только для couta
#include "TQueue.h"
#include <fstream>

typedef TreeNode* TTree;
typedef int datatype;

struct TreeNode
{
	datatype data;
	TreeNode *  left;
	TreeNode * right;
};

typedef TreeNode* TTree;
typedef int datatype;

bool isEmpty(TTree root);
void initTree(TTree& root);
void initTree(TTree& root, datatype elem);
void attachLeftSon(TTree root, datatype elem);
void attachLeftSubtree(TTree root, TTree subtree);
void deleteLeftSubtree(TTree root, TTree subtree);
void copyTree(TTree root, TTree& newRoot);
TTree getLeftSubtree(TTree root);
void destroyTree(TTree& root);
void preeorder(TTree root);
void inorder(TTree root);
void postfix(TTree root);
//void infixIterative(TTree root);
void breadthTraverse(TTree root);
TTree createFormula(std::ifstream& fin);
std::string printStr(TTree root);
int calcFormula(TTree root);
void createBalancedTree(std::ifstream& fin, TTree& root);
TTree createNodes(int nodeCount, std::ifstream& file);