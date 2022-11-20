#pragma once
#include <iostream>
#include <fstream>
#include <string>

typedef int datatype;

struct TreeNode
{
	datatype data;
	TreeNode* left;
	TreeNode* right;
};

typedef TreeNode* TTree;

bool isEmpty(TTree root);
void initTree(TTree& root);
void initTree(TTree& root, datatype elem);
void attachLeftSon(TTree root, datatype elem);
void attachRightSon(TTree root, datatype elem);
void attachLeftSubtree(TTree root, TTree subtree);
void attachRightSubtree(TTree root, TTree subtree);
void deleteLeftSubtree(TTree root, TTree subtree);
void deleteRightSubtree(TTree root, TTree subtree);
void copyTree(TTree root, TTree& newRoot);
TTree getLeftSubtree(TTree root);
void destroyTree(TTree& root);
void preeorder(TTree root);
void inorder(TTree root);
void postfix(TTree root);
//void infixIterative(TTree root);
//void breadthTraverse(TTree root);
TTree createFormula(std::ifstream& fin);
//std::string printStr(TTree root);
int calcFormula(TTree root);
void createBalancedTree(std::ifstream& fin, TTree& root);
TTree createNodes(int nodeCount, std::ifstream& file);
void print_Tree(TTree root, int level, std::ostream & stream);
int count(TTree root, int level, int cur_level);